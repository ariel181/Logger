#include "loggermennager.h"
#include "logconfig.h"
#include "loghelper.h"
#include "logrecorder.h"
#include <iostream>

//LogRecorder* LoggerMennager::_record = nullptr;

LoggerMennager::LoggerMennager()
{
        qDebug()<<Q_FUNC_INFO;
    _record.reset(new LogRecorder(gLogConfig().filePath()));
}

void LoggerMennager::setLog(const LogMessage item)
{
        qDebug()<<Q_FUNC_INFO;
    const QString pom = LogHelper::genSimpleText(item);

    if(gLogConfig().printConsol()) {
        std::cout<<pom.toStdString()<<std::endl;
    }
    _record->setData(pom);
}
