#include "logger.h"
#include <iostream>
#include <QDateTime>
#include <QStringList>
#include "src/logrecorder.h"
#include "src/macro.h"

#define FILE_NAME "./log.text"

LogRecorder* Logger::_record = new LogRecorder(FILE_NAME);


Logger::Logger(LogMessage content) :
   _printConsol(true)
  ,_makSpace(true)
 ,_thredName(true)
  ,_content(content)
{

}

Logger::~Logger()
{
    setLog(_content);
}

void Logger::setLog(const LogMessage item)
{

    QString pom;

    pom += QString("<")
        + item._dateTime.toString(EXP_DATETIMEFORMAT)
        + ">"
        + " "
        + getHeder(item._category)
        + item._text
        + "\n" ;

    if(_printConsol) {

        if(_thredName) {

            QString name = QThread::currentThread()->objectName() ;
            pom = name + " " + pom;

        }

        std::cout<<pom.toStdString()<<std::flush;

    }

    _record->setData(pom);

}

Logger &Logger::mabyspace()
{

    if(_makSpace)
        _content._text += " ";

    return *this;

}

Logger &Logger::operator <<(const QString t)
{

    _content._text += t;

    return mabyspace();

}

//TODO zrobienie osobnej klasy do formatowania
QString Logger::getHeder(const Category cat)
{
    switch (cat) {
    case Category::OK:
        return "OK:\t";
        break;
    case Category::DEBUG:
        return "Debug:\t";
        break;
    case Category::ERROR:
        return "Error:\t";
        break;
    case Category::INFO:
        return "Info:\t";
        break;
    case Category::USER:
        return "User:\t";
        break;
    default:
        return "NULL";
        break;
    }
}


