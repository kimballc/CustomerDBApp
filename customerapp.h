#ifndef CUSTOMERAPP_H
#define CUSTOMERAPP_H

#include <QMainWindow>
#include <string>

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

private:
    Ui::CustomerApp *ui;
    // opens a connection to the database & retrieves your customer info
    void connectToDb();
    // updates your customer record in the database
    void updateDb(QString &lastname, QString &email,
                      QString &city, QString &state);

};

#endif // CUSTOMERAPP_H
