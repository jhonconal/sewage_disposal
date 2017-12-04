#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QApplication>

class IconHelper : public QObject
{
    Q_OBJECT
private:
    explicit IconHelper(QObject *parent = 0);
    QFont iconFont;
    static IconHelper* _instance;

public:
    static IconHelper* Instance()
    {
        static QMutex mutex;
        if (!_instance) {
            QMutexLocker locker(&mutex);
            if (!_instance) {
                _instance = new IconHelper;
            }
        }
        return _instance;
    }

    void setLabelIcon(QLabel* lab, QChar c, int size = 10);
    void setButtonIcon(QPushButton* btn, QChar c, int size = 10);

};

#endif // ICONHELPER_H
