#ifndef CUSTOMERAPP_H
#define CUSTOMERAPP_H

#include <QMainWindow>
#include <string>
#include "customerdata.h"
#include "customerlistmodel.h"


namespace Ui {
class CustomerApp;
}

class CustomerApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerApp(QWidget *parent = 0);
    ~CustomerApp();

private slots:
    void on_updateButton_clicked();

    void on_actionExit_triggered();

    void on_customerListView_clicked(const QModelIndex &index);

private:
    Ui::CustomerApp *ui;
    CustomerData data;
    void showCustomer(const QModelIndex &);
    CustomerListModel* listModel;
};

#endif // CUSTOMERAPP_H
