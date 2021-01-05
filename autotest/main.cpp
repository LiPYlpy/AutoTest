#include "widget.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QSplashScreen *splash=new QSplashScreen;
//    splash->setPixmap(QPixmap("C:/Users/LPY/Desktop/build-autotest_v4-Desktop_Qt_5_9_9_MinGW_32bit-Release/release/yjcs.png"));//此时图片地址为直接在debug下
//    splash->show();

//    Qt::Alignment topRight =Qt::AlignRight |Qt::AlignTop;
//    splash->showMessage(QObject::tr("Setting up the main window ..."),
//                          topRight, Qt::white);
//    a.processEvents();
    Widget w;
//    splash->showMessage(QObject::tr("Loading modules ..."),
//                          topRight,Qt::white);

//    splash->showMessage(QObject::tr("Establishing connection..."),
//                          topRight,Qt::white);
//    QDateTime n2=QDateTime::currentDateTime();
//    QDateTime now;
//    do{
//    now=QDateTime::currentDateTime();
//    } while (n2.secsTo(now)<=3);//3为需要延时的秒数
    w.show();
//    splash->finish(&w);
//    delete splash;
    return a.exec();
}
