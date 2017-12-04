#include "sewagecurve.h"
#include "ui_sewagecurve.h"

SewageCurve::SewageCurve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SewageCurve)
{
    ui->setupUi(this);
    initWnd();
    initParm();
}

SewageCurve::~SewageCurve()
{
    delete ui;
}

void SewageCurve::initWnd()
{

}

void SewageCurve::initParm()
{
    m_dataTimer = new QTimer();
    m_dataTimer->setInterval(50);
    connect(m_dataTimer,SIGNAL(timeout()),this,SLOT(slotRealTimeData()));
    m_sysTimer = new QTimer();
    m_sysTimer->setInterval(1000);
    connect(m_sysTimer,SIGNAL(timeou()),this,SLOT(slotSystemTime()));
}

void SewageCurve::setYAxisValue(qreal value, ENUM_SEWAGE type)
{
    if(type==SEWAGE){
        m_YAxisValue = value;
    }else if (type==SEWAGE_2) {
        m_YAxisValue_2 = value;
    }else if (type == SEWAGE_3) {
        m_YAxisValue_3 = value;
    }
}

void SewageCurve::mousePressEvent(QMouseEvent *event)
{

    return QWidget::mousePressEvent(event);
}

void SewageCurve::mouseMoveEvent(QMouseEvent *event)
{

    return QWidget::mouseMoveEvent(event);
}

void SewageCurve::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<Q_FUNC_INFO;
    if(event->button()==Qt::LeftButton){
#ifdef AUTO_DESKTOP
        if(this->isFullScreen()){
            this->showNormal();
        }else {
            this->showFullScreen();
        }
#else
        if(this->isMaximized()){
            this->showNormal();
        }else {
            this->showMaximized();
        }
#endif
    }
    return QWidget::mouseDoubleClickEvent(event);
}

void SewageCurve::slotRealTimeData()
{

}

void SewageCurve::slotSystemTime()
{

}
