#ifndef LOGGERMENNAGER_H
#define LOGGERMENNAGER_H

#include "logmessage.h"
#include "logrecorder.h"
#include <memory>
#include <QDebug>

class LogRecorder;

class LoggerMennager
{
public:
    static LoggerMennager& getInstancea() {
        qDebug()<<Q_FUNC_INFO;
        static LoggerMennager logmen;
        return logmen;
    }

    void setLog(const LogMessage item);

private:

    LoggerMennager();
    LoggerMennager(const LoggerMennager&)= delete;
    LoggerMennager& operator=(const LoggerMennager&)= delete;

    std::unique_ptr<LogRecorder> _record;
};


#define gLogMenager LoggerMennager::getInstancea


#endif // LOGGERMENNAGER_H
