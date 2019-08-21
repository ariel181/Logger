#include <QCoreApplication>
#include "src/loggercreator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    _USER()<<"log User";
    _OK()<<"log Ok";
    _DEBUG()<<"log debug";
    _INFO ()<<"log info" ;
    _ERROR()<<"log error";

    return a.exec();
}
