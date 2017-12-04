#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "helper/iconhelper.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initWnd();
    init();
    initCenterStackWidgetPage1();
#ifdef AUTO_DESKTOP
    this->showFullScreen();
#else
    this->setGeometry(0,0,1024,768);
#endif
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initWnd()
{
    QIcon icon;
    icon.addFile(tr(":/Resc/icons/home.png"));
    ui->homeToolButton->setIcon(icon);
    icon.addFile(tr(":/Resc/icons/curve.png"));
    ui->itemToolButton->setIcon(icon);
    icon.addFile(tr(":/Resc/icons/item.png"));
    ui->itemToolButton_2->setIcon(icon);
    icon.addFile(tr(":/Resc/icons/item.png"));
    ui->itemToolButton_3->setIcon(icon);
    icon.addFile(tr(":/Resc/icons/setting.png"));
    ui->itemToolButton_4->setIcon(icon);
    IconHelper::Instance()->setButtonIcon(ui->settingButton,QChar(0xf039),24); 
    ui->centerStackWidget->setCurrentIndex(2);
}

void MainWidget::init()
{
    getSystemInfo();
    slot_setTimeInfo();
    system_timer = new QTimer();
    connect(system_timer,SIGNAL(timeout()),this,SLOT(slot_setTimeInfo()));
    system_timer->start(1000);
    //Page参数初始化
    m_currentValue=0;m_currentValue2=0;m_currentValue3=0;
    m_alarmValue=0;m_alarmValue2=0;m_alarmValue3=0;
}

QLocale::Country MainWidget::getSystemInfo()
{
   QLocale locale;
   m_country = locale.country();
   return m_country;
}

void MainWidget::initCenterStackWidgetPage1()
{
    initGuiSewageCruve();
    updateTimer=new QTimer(this);
    updateTimer->start(400);
#ifdef DESKTOP_DEMO
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(AsewageRealTimeDataSlot()));
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(BsewageRealTimeDataSlot()));
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(CsewageRealTimeDataSlot()));
#endif
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->resizeSection(0,325);
    ui->tableWidget->horizontalHeader()->resizeSection(1,325);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:lightblue;border: 1px solid #6c6c6c;}");    //设置表头字体，颜色，模式
    for(int i=0;i<ui->tableWidget->colorCount();i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("污染物 %1").arg(i));
        newItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, newItem);
    }
    for(int i=0;i<ui->tableWidget->colorCount();i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1 mmg/L").arg(0));
        newItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, newItem);
    }
    for(int i=0;i<ui->tableWidget->colorCount();i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1 mmg/L").arg(0));
        newItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 2, newItem);
    }
}

void MainWidget::initGuiSewageCruve()
{
    QPen pen;
    pen.setWidth(2);
    //设置纵坐标名称
    ui->sewagePlot->setWindowTitle(tr("污染物浓度实时监测曲线"));
    ui->sewagePlot->yAxis->setLabel(tr("污染物浓度(单位:mmg/L)"));
    ui->sewagePlot->legend->setVisible(true);
    //设置坐标颜色/坐标名称颜色
    ui->sewagePlot->yAxis->setLabelColor(QColor(255,0,128));
    ui->sewagePlot->xAxis->setTickLabelColor(QColor(0,128,0));
    ui->sewagePlot->yAxis->setTickLabelColor(QColor(0,128,0));
    ui->sewagePlot->xAxis->setBasePen(QPen(QColor(0,128,0),2));
    ui->sewagePlot->yAxis->setBasePen(QPen(QColor(0,128,0),2));
    ui->sewagePlot->xAxis->setTickPen(QPen(QColor(0,128,0),2));
    ui->sewagePlot->yAxis->setTickPen(QPen(QColor(0,128,0),2));
    ui->sewagePlot->xAxis->setSubTickPen(QPen(QColor(0,128,0),2));
    ui->sewagePlot->yAxis->setSubTickPen(QPen(QColor(0,128,0),2));

    //设置画布背景色
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(60, 60, 60));
//    ui->sewagePlot->setBackground(plotGradient);

    //设置坐标背景色
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(80, 80, 80));
//    ui->sewagePlot->axisRect()->setBackground(axisRectGradient);

    //设置图例提示位置及背景色
    ui->sewagePlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    ui->sewagePlot->legend->setBrush(QColor(255, 255, 255, 10));//透明背景

    ui->sewagePlot->addGraph();
    pen.setColor(QColor(255, 0, 127));
    ui->sewagePlot->graph(0)->setPen(pen);
    ui->sewagePlot->graph(0)->setName("污染物 1");
    ui->sewagePlot->graph(0)->setBrush(QBrush(QColor(255,0,100,10)));
    ui->sewagePlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);

    ui->sewagePlot->addGraph();
    pen.setColor(QColor(85, 170, 0));
    ui->sewagePlot->graph(1)->setPen(pen);
    ui->sewagePlot->graph(1)->setName("污染物 2");
    ui->sewagePlot->graph(1)->setBrush(QBrush(QColor(85,150,0,10)));
    ui->sewagePlot->graph(1)->setScatterStyle(QCPScatterStyle::ssCrossCircle);

    ui->sewagePlot->addGraph();
    pen.setColor(QColor(255, 170, 0));
    ui->sewagePlot->graph(2)->setPen(pen);
    ui->sewagePlot->graph(2)->setName("污染物 2");
    ui->sewagePlot->graph(2)->setBrush(QBrush(QColor(255,150,0,10)));
    ui->sewagePlot->graph(2)->setScatterStyle(QCPScatterStyle::ssDiamond);
    //设置静态曲线的横坐标范围及自适应横坐标
    ui->sewagePlot->yAxis->setRange(0, 1000+1, Qt::AlignLeft);
    ui->sewagePlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->sewagePlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->sewagePlot->xAxis->setAutoTickStep(false);
    ui->sewagePlot->xAxis->setTickStep(1);

    ui->sewagePlot->xAxis->grid()->setSubGridVisible(true);
    ui->sewagePlot->yAxis->grid()->setSubGridVisible(true);

    ui->sewagePlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
    ui->sewagePlot->replot();
}

void MainWidget::slot_setTimeInfo()
{
//    "星期四, 20 7月 17 13:39:26" / Fri Jul 21 00:55:37 DST 2017
//    QString format = "dddd, d MMMM yy hh:mm:ss";
    const QString format = "dddd/d/MMMM/yyyy/hh/mm/ss";
    QString time   = QDateTime::currentDateTime().toString(format);
    m_week = time.section('/',0,0);
    m_day  = time.section('/',1,1);
    m_month = time.section('/',2,2);
    m_year = time.section('/',3,3);
    m_hour = time.section('/',4,4);
    m_minute = time.section('/',5,5);
    m_second = time.section('/',6,6);
    //2017 年 07 月 20 日 星期 四
#ifdef EN_REGIONAL_FORMAT
    QString date = tr("%1 %2 %3 %4").arg(m_week).arg(m_month).arg(m_day).arg(m_year);
#else
    QString date = tr("%1 年 %2 %3 日 %4").arg(m_year).arg(m_month).arg(m_day).arg(m_week);
#endif
    ui->dateLabel->setText(date);
    ui->hourLabel->setText(m_hour);
    ui->minuteLabel->setText(m_minute);
    ui->secondLabel->setText(m_second);
    update();
    QString format_2 = "d MMMM yy hh:mm:ss";
    QString time_2  = QDateTime::currentDateTime().toString(format_2);
    ui->timeLineEdit->setText(tr("%1").arg(time_2));
}


void MainWidget::on_homeToolButton_clicked()
{
   ui->centerStackWidget->setCurrentIndex(2);
}

void MainWidget::on_itemToolButton_clicked()
{
    ui->centerStackWidget->setCurrentIndex(0);
}

void MainWidget::on_itemToolButton_2_clicked()
{
     ui->centerStackWidget->setCurrentIndex(1);
}

void MainWidget::on_itemToolButton_3_clicked()
{
     ui->centerStackWidget->setCurrentIndex(3);
}

void MainWidget::on_itemToolButton_4_clicked()
{
    ui->centerStackWidget->setCurrentIndex(4);
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
//    qDebug()<<Q_FUNC_INFO;
    if(event->type() == QEvent::MouseButtonPress)
    {
        m_posX.clear();
        m_posY.clear();
    }
    return QWidget::mousePressEvent(event);
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug()<<Q_FUNC_INFO;
    if(event->type() == QEvent::MouseMove)
    {
        m_posX.append(event->x());
        m_posY.append(event->y());
    }
    if(m_posX.last()-m_posX.first()>=0){//左边滑动
        if(qAbs(m_posX.last()-m_posX.first())>=200){
            if((ui->centerStackWidget->currentIndex()>0)||
             (ui->centerStackWidget->currentIndex()<ui->centerStackWidget->count())){
//                ui->centerStackWidget->setCurrentIndex(ui->centerStackWidget->currentIndex()-1);
                ui->centerStackWidget->forward();
            }
        }
    }else {//右边滑动
        if(qAbs(m_posX.last()-m_posX.first())>=200){
            if((ui->centerStackWidget->currentIndex()>0)||
             (ui->centerStackWidget->currentIndex()<ui->centerStackWidget->count())){
//                ui->centerStackWidget->setCurrentIndex(ui->centerStackWidget->currentIndex()+1);
                ui->centerStackWidget->next();
            }
        }
    }
    return QWidget::mouseMoveEvent(event);
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug()<<Q_FUNC_INFO;

    return QWidget::mouseMoveEvent(event);
}

void MainWidget::on_centerStackWidget_currentChanged(int index)
{
    switch (index) {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    default:
        break;
    }
}
#ifdef DESKTOP_DEMO
void MainWidget::AsewageRealTimeDataSlot()
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(255, 0, 127));
    ui->sewagePlot->graph(0)->setPen(pen);
    //ui->qCustomPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->sewagePlot->graph(0)->setAntialiasedFill(false);
    ui->sewagePlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->sewagePlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->sewagePlot->xAxis->setAutoTickStep(false);
    ui->sewagePlot->xAxis->setTickStep(1);
    ui->sewagePlot->axisRect()->setupFullAxesBox();

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int xxx=qrand()%1000;
        ui->sewagePlot->graph(0)->addData(key, xxx);
        ui->sewagePlot->graph(0)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->sewagePlot->graph(0)->rescaleValueAxis();
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->sewagePlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->sewagePlot->replot();
}

void MainWidget::BsewageRealTimeDataSlot()
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(85, 170, 0));
    ui->sewagePlot->graph(1)->setPen(pen);
    //ui->qCustomPlot->graph(1)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->sewagePlot->graph(1)->setAntialiasedFill(false);
    ui->sewagePlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->sewagePlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->sewagePlot->xAxis->setAutoTickStep(false);
    ui->sewagePlot->xAxis->setTickStep(1);
    ui->sewagePlot->axisRect()->setupFullAxesBox();

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int xxx=qrand()%1000;
        ui->sewagePlot->graph(1)->addData(key, xxx);
        ui->sewagePlot->graph(1)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->sewagePlot->graph(1)->rescaleValueAxis();
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->sewagePlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->sewagePlot->replot();
}

void MainWidget::CsewageRealTimeDataSlot()
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(255, 170, 0));
    ui->sewagePlot->graph(2)->setPen(pen);
    //ui->qCustomPlot->graph(2)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->sewagePlot->graph(2)->setAntialiasedFill(false);
    ui->sewagePlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->sewagePlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->sewagePlot->xAxis->setAutoTickStep(false);
    ui->sewagePlot->xAxis->setTickStep(1);
    ui->sewagePlot->axisRect()->setupFullAxesBox();

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int xxx=qrand()%1000;
        ui->sewagePlot->graph(2)->addData(key, xxx);
        ui->sewagePlot->graph(2)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->sewagePlot->graph(2)->rescaleValueAxis();
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->sewagePlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->sewagePlot->replot();
}
#endif
