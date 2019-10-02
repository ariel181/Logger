#include "loggercreator.h"
#include "loggermennager.h"
#include <QDebug>

LoggerCreator::LoggerCreator(int line, const char *file, const char *method, Category cat):
    content(line,file,method,cat)
{

        qDebug()<<Q_FUNC_INFO;
}

Logger LoggerCreator::logger() const
{

        qDebug()<<Q_FUNC_INFO;
    Logger logger(content,gLogMenager());

    return logger;

}
