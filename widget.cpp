#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_time(2000),
    state("green")
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/img/Green.jpg"));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateLight()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime(int time) {
    if (time == 0) {
        m_time = 2000;
    } else {
        m_time = time*1000;
    }
    timer->start(m_time);
}

void Widget::changeState(QString s) {
    state = s;
}

void Widget::updateLight() {
    if (state == "green") {
        ui->label->setPixmap(QPixmap(":/new/img/Yellow.jpg"));
        changeState("yellow");
    } else if (state == "yellow") {
        ui->label->setPixmap(QPixmap(":/new/img/Red.jpg"));
        changeState("red");
    } else if (state == "red") {
        ui->label->setPixmap(QPixmap(":/new/img/Green.jpg"));
        changeState("green");
    }
}
