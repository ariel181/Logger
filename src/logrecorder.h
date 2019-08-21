#ifndef LOGRECORDER_H
#define LOGRECORDER_H

#include <QFile>
#include <QMutex>
#include <QObject>
#include <QQueue>
#include <QTextStream>
#include <QThread>
#include <QString>


class LogRecorder : public QObject
{
    Q_OBJECT
public:
    explicit LogRecorder(QString file, QObject *parent = 0);
    ~LogRecorder();
    void setData(QString pom);
signals:

public slots:
    void runWork();

private:
    void openFile();

    bool _doWork;
    QString _filePos;
    QThread* _thred;
    QQueue<QString> _qMess;
    QFile _outFile;
    QTextStream* _strem;
    QMutex _mutex;
};

#endif // LOGRECORDER_H
