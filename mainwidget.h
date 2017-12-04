#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QLocale>
#include <QToolTip>
#include <QToolButton>
#include <QMouseEvent>
#include <QTableWidgetItem>
#include "sewagecurve.h"
#include "qanimationstackedwidget.h"
#define   DESKTOP_DEMO   //桌面演示
//#define  AUTO_DESKTOP //定义自动适配显示器
#define  iMX6_DEVICE  //定义专用嵌入式设备
//#define  EN_REGIONAL_FORMAT  //英文区域格式
namespace Ui {
class MainWidget;
}
/**
 * @brief The MainWidget class
 * 主界面类
 */
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void  initWnd();
    void  init();
    QLocale::Country getSystemInfo();
    //Page1 界面初始化
    void initCenterStackWidgetPage1();
    void initGuiSewageCruve();
//    void initCenterStackWidgetPage2();
//    void initCenterStackWidgetHome();
//    void initCenterStackWidgetPage4();
//    void initCenterStackWidgetPage5();
private slots:

    void on_homeToolButton_clicked();

    void on_itemToolButton_clicked();

    void on_itemToolButton_2_clicked();

    void on_itemToolButton_3_clicked();

    void on_itemToolButton_4_clicked();
    /**
     * @brief on_centerStackWidget_currentChanged
     * @param index
     *
     */
    void on_centerStackWidget_currentChanged(int index);
    //三种曲线槽函数
#ifdef DESKTOP_DEMO
    void AsewageRealTimeDataSlot();
    void BsewageRealTimeDataSlot();
    void CsewageRealTimeDataSlot();
#else

#endif
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public slots:
    void slot_setTimeInfo();
private:
    Ui::MainWidget *ui;
    //字符串类型时间
    QString m_year,m_month,m_day,m_week,
            m_hour,m_minute,m_second;
    QTimer *system_timer;
    QLocale::Country m_country;
    QVector<qreal> m_posX,m_posY;
    //Page1界面曲线
    QTimer *updateTimer;
    qreal m_currentValue,m_currentValue2,m_currentValue3;
    qreal m_alarmValue,m_alarmValue2,m_alarmValue3;
    QTableWidgetItem *m_currentItem,*m_alarmItem;
};
#endif // MAINWIDGET_H
