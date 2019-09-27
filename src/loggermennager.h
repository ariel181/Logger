#ifndef LOGGERMENNAGER_H
#define LOGGERMENNAGER_H

#include "logmessage.h"
#include <memory>

class LogRecorder;

class LoggerMennager
{
public:
    static LoggerMennager& getInstancea() {
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
