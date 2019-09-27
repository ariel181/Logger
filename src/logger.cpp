#include "logger.h"
#include <iostream>
#include <QDateTime>
#include <QStringList>
#include <QPoint>
#include <QPointF>
#include <QRectF>
#include "logrecorder.h"
#include "loggermennager.h"


Logger::Logger(LogMessage content, LoggerMennager &menager) :
  _content{content}
    ,_menager{menager}
{

}

Logger::~Logger()
{
    _menager.setLog(_content);
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
