#ifndef LOGGERCREATOR_H
#define LOGGERCREATOR_H

#include "src/logger.h"


class LoggerCreator {

public:
    LoggerCreator(int line, const char* file, const char* method, Category cat);
    Logger logger() const;
private:
    LogMessage content;

};

#define _USER LoggerCreator(__LINE__,__FILE__,Q_FUNC_INFO,Category::USER).logger
#define _OK LoggerCreator(__LINE__,__FILE__,Q_FUNC_INFO,Category::OK).logger
#define _DEBUG LoggerCreator(__LINE__,__FILE__,Q_FUNC_INFO,Category::DEBUG).logger
#define _INFO LoggerCreator(__LINE__,__FILE__,Q_FUNC_INFO,Category::INFO).logger
#define _ERROR LoggerCreator(__LINE__,__FILE__,Q_FUNC_INFO,Category::ERROR).logger

#endif // LOGGERCREATOR_H
