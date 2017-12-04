#ifndef SEWAGECURVE_H
#define SEWAGECURVE_H
#include "3rdparty/qserialport/qextserialport.h"
#include "qcustomplot.h"
#include <QWidget>
#include <QDebug>
#include <QVector>
#include <QTimer>
#include <QMouseEvent>

//污染物类型
enum ENUM_SEWAGE
{
    SEWAGE,
    SEWAGE_2,
    SEWAGE_3
};

namespace Ui {
class SewageCurve;
}

class SewageCurve : public QWidget
{
    Q_OBJECT

public:
    explicit SewageCurve(QWidget *parent = 0);
    ~SewageCurve();
    void initWnd();
    void initParm();
    /**
     * @brief setYAxisValue
     * @param value 传入值
     * @param type 污染物类型
     */
    void setYAxisValue(qreal value,ENUM_SEWAGE type);
protected:
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseDoubleClickEvent(QMouseEvent*event);

private slots:
    /**
     * @brief slotRealTimeData
     * 实时曲线槽函数
     */
    void slotRealTimeData();
    /**
     * @brief slotSystemTime
     * 系统时间
     */
    void slotSystemTime();
private:
    Ui::SewageCurve *ui;
    //曲线 GUI
    QString  m_yLabel,m_xLabel;
    QString  m_sweageLegend,
             m_sweageLegend_2,
             m_sweageLegend_3;
    QString  m_legendColor;//
    //三种曲线data
    double m_YAxisValue,
           m_YAxisValue_2,
           m_YAxisValue_3;
    QTimer  *m_dataTimer,*m_sysTimer;
};

#endif // SEWAGECURVE_H
