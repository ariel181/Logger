#include "loggercreator.h"

LoggerCreator::LoggerCreator(int line, const char *file, const char *method, Category cat):
    content(line,file,method,cat)
{

}

Logger LoggerCreator::logger() const
{

    Logger logger(content);

    return logger;

}