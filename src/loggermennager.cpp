#include "loggermennager.h"
#include "logconfig.h"
#include "loghelper.h"
#include "logrecorder.h"
#include <iostream>

//LogRecorder* LoggerMennager::_record = nullptr;

LoggerMennager::LoggerMennager()
{
    _record.reset(new LogRecorder(gLogConfig().filePath()));
}

void LoggerMennager::setLog(const LogMessage item)
{
    const QString pom = LogHelper::genSimpleText(item);

    if(gLogConfig().printConsol()) {
        std::cout<<pom.toStdString()<<std::endl;
    }
    _record->setData(pom);
}
