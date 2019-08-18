#include "src/logrecorder.h"
#include "src/logger.h"
#include "src/loggercreator.h"

QThread* LogRecorder::_thred = new QThread;

LogRecorder::LogRecorder(QString file, QObject *parent) : QObject(parent)
  ,_doWork(true)
  ,_filePos(file)
{

    openFile();
    _thred->setParent(this);
//    _thred = new QThread(this);
    _thred->setObjectName("Log Thread");
    connect(_thred,&QThread::started,this,&LogRecorder::runWork);
    this->moveToThread(_thred);
    _thred->start();

}

LogRecorder::~LogRecorder()
{

    _doWork = false;
    _thred->wait();
    _strem->flush();
    if(_outFile.isOpen()) _outFile.close();
}

void LogRecorder::openFile()
{
    _outFile.setFileName(_filePos);
    _outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    if(_outFile.isOpen()) {
        _strem = new QTextStream(&_outFile);
    } else {
//        error("File not Open");
        _strem = new QTextStream(stdout);
    }
}

void LogRecorder::setData(QString pom)
{
    QMutexLocker locker(&_mutex);
    _qMess.push_back(pom);
}
void LogRecorder::runWork()
{

    while (_doWork) {

        _mutex.lock();
        while (!_qMess.isEmpty()) {
            const QString pom = _qMess.dequeue();
                *_strem << pom;
        }
        _mutex.unlock();

        _OK()<<"Go sleep";
        _strem->flush();
        QThread::sleep(10);
    }

}