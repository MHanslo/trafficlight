#include "widget.h"
#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    int time = QInputDialog::getInt(0, "Traffic Timer", "Enter traffic light time in seconds");
    w.updateTime(time);
    w.show();
    return a.exec();
}
