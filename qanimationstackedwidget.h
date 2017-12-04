#ifndef QANIMATIONSTACKEDWIDGET_H
#define QANIMATIONSTACKEDWIDGET_H

#include <QStackedWidget>
#include <QPropertyAnimation>

//枚举值，Widget切换的方向
typedef enum {
    LeftToRight,
    RightToLeft
}Direction;

/**
 * 带切换动画的stackWidget
 * 原理：如果要切换QStackedWidget当前的widget可以调用QStackedWidget::setCurrentIndex();
 * 所以在点击切换的时候播放一个动画，然后将第一个Widget和下一个Widget的过度过程绘制出来，屏蔽掉父类的QWidget函数
 * 当动画完成可以调用QStackedWidget::setCurrentIndex()函数实现界面的真正切换
 */
class QAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit QAnimationStackedWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    //设置动画持续的间隔
    void setDuration(int );

    ~QAnimationStackedWidget();

signals:

public slots:
    //属性动画值改变的槽
    void valueChanged_slot(QVariant );
    //动画切换完成
    void animationFinished();
    //前一页
    void next();
    //下一页
    void forward();

private:
    void paintPrevious(QPainter &, int);

    void paintNext(QPainter &, int);

private:
    QPropertyAnimation *animation; //动画框架
    int duration;                   //动画的持续时间
    bool isAnimation;               //是否正在动画
    QVariant       currentValue;    //被Animation动画改变的值
    int         widgetCount;        //保存当前StackWidget里面的子成员数
    int         nextIndex;          //下一个要切换的索引
    Direction   direction;          //方向
};

#endif // QANIMATIONSTACKEDWIDGET_H
