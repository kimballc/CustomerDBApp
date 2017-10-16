#include "customerapp.h"
#include "ui_customerapp.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>
#include <iostream>
#include <string>

CustomerApp::CustomerApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerApp)
{
    ui->setupUi(this);

    // get the customer info from CustomerData & display it
    this->showCustomer(data.getCustomer());
}


CustomerApp::~CustomerApp()
{
    delete ui;
}

void CustomerApp::on_updateButton_clicked()
{
    // Get the data from the GUI;
    //
    // Use the text() method of the line edit text boxes to get your data.
    //
    // Use toStdString() to convert the return QString to a std::string.
    //
    std::string lastName = ui->lastNameData->text().toStdString();
    std::string email = ui->emailData->text().toStdString();
    std::string city = ui->cityData->text().toStdString();
    std::string state = ui->stateData->text().toStdString();

      // If the database update was successful, print a message
    if(data.updateCustomer(lastName, email, city, state))
    {
        // display a message box
        QMessageBox::information(
            this,
            tr("Record Updated"),
            tr("Your customer info was updated successfully!" )
        );
    }

}

void CustomerApp::on_actionExit_triggered()
{
    exit(0);
}

void CustomerApp::showCustomer(Customer c)
{
    QString firstName = QString::fromStdString(c.getFirstName());
    QString lastName = QString::fromStdString(c.getLastName());
    QString email = QString::fromStdString(c.getEmail());
    QString city = QString::fromStdString(c.getHomeTown());
    QString state = QString::fromStdString(c.getHomeState());

    // Set the text of the widgets; call the setText(QString) method
    // on labels & text boxes
    ui->firstNameData->setText(firstName);
    ui->lastNameData->setText(lastName);
    ui->emailData->setText(email);
    ui->cityData->setText(city);
    ui->stateData->setText(state);

}
