#include "logger.h"
#include <iostream>
#include <QDateTime>
#include <QStringList>
#include <QPoint>
#include <QPointF>
#include <QRectF>
#include "logrecorder.h"
#include "macro.h"

#define FILE_NAME "./log.txt"

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

    const QString pom = genLogText(item);

    if(_printConsol) {
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

Logger &Logger::operator <<(const char *t){
    _content._text += QString::fromUtf8(t);
    return mabyspace();
}

Logger &Logger::operator <<(const QRectF t)
{
    _content._text += QString("(x:%1 y:%2 h:%3 w:%4)")
            .arg(t.x())
            .arg(t.y())
            .arg(t.height())
            .arg(t.width());
}

Logger &Logger::operator <<(const QPointF t)
{
    _content._text += QString("(%1,%2)").arg(t.x()).arg(t.y());
    return mabyspace();
}

Logger &Logger::operator <<(const QPoint t)
{
    _content._text += QString("(%1,%2)").arg(t.x()).arg(t.y());
    return mabyspace();
}

Logger &Logger::operator <<(const int t)
{
    _content._text += QString::number(t);
    return mabyspace();

}

Logger &Logger::operator <<(const QString t)
{

    _content._text += t;

    return mabyspace();

}

//TODO zrobienie osobnej klasy do formatowania
QString Logger::getHeder(const LogMessage cat) const
{
    switch (cat._category) {
    case Category::OK:
        return "OK:\t";
        break;
    case Category::DEBUG:
        return "Debug:\t" + cat._method + " " ;
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

const QString Logger::genLogText(const LogMessage item) const
{

    QString pom;
    QString thredName;

    if(_thredName) {
        thredName = QString("<%1> ").arg(QThread::currentThread()->objectName());
    }

    pom += QString("<%1> ").arg(item._dateTime.toString(EXP_DATETIMEFORMAT));
    pom += thredName;
    pom += getHeder(item);
    pom += item._text;
    pom +="\n" ;

    return pom;
}


