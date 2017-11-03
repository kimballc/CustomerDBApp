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

    // ADDED - initializes the customer list model;
    // gets the customers from CustomerData and passes it
    // to the model
    listModel = new CustomerListModel(data.getCustomers());

    // ADDED - sets the model of the customer list view
    // to 'listModel'
    ui->customerListView->setModel(listModel);

          // ADDED - sets the first item as the current selection
          ui->customerListView->setCurrentIndex(this->listModel->index(0,0));

    // UPDATED - now passes the CustomerListModel index of
    // the first item in the customer list
    this->showCustomer(this->listModel->index(0,0));
}



CustomerApp::~CustomerApp()
{
    delete listModel;   //dynamically remove listModel from memory
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
    // ADDED - get the index of current customer from list view
    int index = ui->customerListView->currentIndex().row();

    // UPDATED - added the index as the first parameter
    if(data.updateCustomer(index, lastName, email, city, state))
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

void CustomerApp::showCustomer(const QModelIndex &index)
{
    Customer c = data.getCustomer(index.row());

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

void CustomerApp::on_customerListView_clicked(const QModelIndex &index)
{
    this->showCustomer(index);
}
