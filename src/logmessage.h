#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <QDateTime>
#include <QThread>


enum class Category {
    NON = -1,
    USER = 0,
    OK = 1,
    DEBUG = 2,
    INFO = 3,
    ERROR = 4,

};

class LogMessage {

public:

    LogMessage(int line, QString file, QString method, Category cat):
           _category{cat}
          ,_line{line}
          ,_file{file}
          ,_method{method}
          ,_text{""}
         ,_threadName{""}
          ,_dateTime{QDateTime::currentDateTime()}
    {

        _threadName = QString("<%1> ").arg(QThread::currentThread()->objectName());

    }

private:
    Category _category;
    QString _line;
    QString _file;
    QString _method;
    QString _text;
    QString _threadName;
    QDateTime _dateTime;

    friend class Logger;
    friend class LogHelper;
};

#endif // LOGMESSAGE_H
