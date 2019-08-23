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




class Logger
{

public:
    Logger(LogMessage content);
    ~Logger();
    void setLog(const LogMessage item);
    Logger &mabyspace();
    Logger &operator <<(const QString t );
    Logger &operator <<(const char* t );
    Logger &operator <<(const int t );
    Logger &operator <<(const QPoint t );
    Logger &operator <<(const QPointF t );
    Logger &operator <<(const QRectF t );

private:
    QString getHeder(const LogMessage cat) const;
    const QString genLogText(const LogMessage item) const;
    static LogRecorder* _record;
    bool _printConsol;
    bool _makSpace;
    bool _thredName;
    LogMessage _content;

};



#endif // GUILOGGER_H
