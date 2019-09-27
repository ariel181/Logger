#include "loghelper.h"
#include "macro.h"
#include <QThread>

LogHelper::LogHelper()
{

}

const QString LogHelper::getHeder(const LogMessage &cat)
{
    switch (cat._category) {
    case Category::OK:
        return "OK:\t";
        break;
    case Category::DEBUG:
        return "Debug:\t" + cat._method + " " ;
        break;
    case Category::ERROR:
        return "Error:\t";
        break;
    case Category::INFO:
        return "Info:\t";
        break;
    case Category::USER:
        return "User:\t";
        break;
    default:
        return "NULL";
        break;
    }
}
const QString LogHelper::genSimpleText(const LogMessage &item)
{

    QString pom;
    QString thredName;

    pom += QString("<%1> ").arg(item._dateTime.toString(EXP_DATETIMEFORMAT));
    pom += getHeder(item);

//    if(_thredName) {
//        pom += thredName;
//    }

    pom += item._text;
    pom +="\n" ;

    return pom;
}
