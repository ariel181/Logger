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
#include "src/logmessage.h"

class LogRecorder;




class Logger
{

public:
    Logger(LogMessage content);
    ~Logger();
    void setLog(const LogMessage item);
    Logger &mabyspace();
    Logger &operator <<(const QString t );
    Logger &operator <<(const char* t ){
        _content._text += QString::fromUtf8(t);
        return mabyspace();
    }

private:
    QString getHeder(const Category cat) const;
    const QString genLogText(const LogMessage item) const;
    static LogRecorder* _record;
    bool _printConsol;
    bool _makSpace;
    bool _thredName;
    LogMessage _content;

};



#endif // GUILOGGER_H
