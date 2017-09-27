#include "customerapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomerApp w;
    w.show();

    return a.exec();
}
