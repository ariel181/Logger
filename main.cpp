#include <QCoreApplication>
#include "src/loggercreator.h"
#include <QPoint>
#include <QRectF>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    _USER() 	<<	"log User";
    _OK()		<<	"log Ok";
    _DEBUG()	<<	"log debug";
    _INFO ()	<<	"log info" ;
    _ERROR()	<<	"log error";

    _INFO()<<QPoint(100,50);
    _INFO()<<QRectF(0,0,100.5,60.89);

    return a.exec();
}
