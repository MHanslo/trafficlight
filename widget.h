#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>
#include <QTimer>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void updateTime(int time);
    ~Widget();

public slots:
    void updateLight();
    void changeState(QString s);

private:
    Ui::Widget *ui;
    int m_time;
    QTimer *timer;
    QString state;
};

#endif // WIDGET_H
