#ifndef CUSTOMERAPP_H
#define CUSTOMERAPP_H

#include <QMainWindow>

namespace Ui {
class CustomerApp;
}

class CustomerApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerApp(QWidget *parent = 0);
    ~CustomerApp();

private:
    Ui::CustomerApp *ui;
};

#endif // CUSTOMERAPP_H
