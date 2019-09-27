#ifndef GUILOGGER_H
#define GUILOGGER_H

#include <QObject>
#include <QString>
#include <QQueue>
#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDateTime>
#include "logmessage.h"

class LogRecorder;
class LoggerMennager;

class Logger
{

public:
    Logger(LogMessage content, LoggerMennager &menager );
    ~Logger();
    Logger &mabyspace();
    Logger &operator <<(const QString t );
    Logger &operator <<(const char* t );
    Logger &operator <<(const int t );
    Logger &operator <<(const QPoint t );
    Logger &operator <<(const QPointF t );
    Logger &operator <<(const QRectF t );

private:
    LogMessage _content;
    LoggerMennager& _menager;
    bool _makSpace{true};

};



#endif // GUILOGGER_H
