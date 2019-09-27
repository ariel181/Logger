#ifndef LOGBUILDER_H
#define LOGBUILDER_H

#include "logmessage.h"

class LogHelper
{
public:
    LogHelper();
    static const QString genSimpleText(const LogMessage& item) ;
    static const QString getHeder(const LogMessage& cat) ;
};

#endif // LOGBUILDER_H
