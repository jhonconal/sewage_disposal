#include "mainwidget.h"
#include "helper/helper.h"
#include "inputTool/frminput.h"
#include <QApplication>
#include <QDebug>
#include <QMovie>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    Helper::SetUTF8Code();//Qt4.x中文支持
#endif
    QApplication::setApplicationName("sewage monitoring");
    //loading 动画加载
    QMovie *movie;
    movie = new QMovie(":/Resc/images/loading.gif");
    QLabel *label= new QLabel("",0);
    label->setMovie(movie);
    label->setScaledContents(true);
    label->setWindowTitle("sewage disposal");
    movie->start();
#ifdef AUTO_DESKTOP
    label->showFullScreen();
#else
    label->setGeometry(0,0,1024,768);
#endif
    label->show();
    Helper::Sleep(8000);

    MainWidget w;
    label->close();
    w.show();
    //为该APP加载输入法(支援中文)
    frmInput::Instance()->Init("center","",12,12);
    return a.exec();
}
