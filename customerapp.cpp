#include "customerapp.h"
#include "ui_customerapp.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>
#include <iostream>

CustomerApp::CustomerApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerApp)
{
    ui->setupUi(this);
    // Connect to the database
    this->connectToDb();

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
        QString lastName = ui->lastNameData->text();
        QString email = ui->emailData->text();
        QString city = ui->cityData->text();
        QString state = ui->stateData->text();

        this->updateDb(lastName, email, city, state);

}

void CustomerApp::on_actionExit_triggered()
{
    exit(0);
}

void CustomerApp::connectToDb()
{
    // create a database connection object
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=jpgrady28.database.windows.net;Database=restaurant;Uid=cs245@jpgrady28;Port=1433;Pwd=C_plus_plus;encrypt=true;trustServerCertificate=false;hostNameInCertificate=*.database.windows.net;loginTimeout=30;");

    // open the connection
    bool ok = db.open();

        // if we connect successfully...
        if(ok)
        {
            // Create a query that can only be read forward;
            // improves performance *dramatically*
            QSqlQuery query;
            query.setForwardOnly(true);

            // Create a prepared statement;
            // Get the customer record whose last name matches yours
            //
            query.prepare("SELECT * FROM customer WHERE lastName = ?");
            query.bindValue(0, "Kimball");

            // If your SQL was OK...
            if(query.exec())
            {
                // while there are still more records in the result set...
                while (query.next())
                {
                    // Note: your customer ID is in the first (0) index
                    std::cout << query.value(0).toInt() << "\t";

                    /*
                     *  NOTE: toString() returns a QString object, not a std::string
                     */

                    // Get the remaining data from the result set
                    QString firstName = query.value(1).toString();
                    QString lastName = query.value(2).toString();
                    QString email = query.value(3).toString();
                    QString city = query.value(4).toString();
                    QString state = query.value(5).toString();

                    // Set the text of the widgets; call the setText(QString) method
                    // on labels & text boxes
                    ui->firstNameData->setText(firstName);
                    ui->lastNameData->setText(lastName);
                    ui->emailData->setText(email);
                    ui->cityData->setText(city);
                    ui->stateData->setText(state);

                 }
             }

          // Close the db
          db.close();
        }
        else {
            std::cout << "Issues" << std::endl;
        }
}

void CustomerApp::updateDb(QString &lastName, QString &email,
                           QString &city, QString &state)
{
    // create a database connection object
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=jpgrady28.database.windows.net;Database=restaurant;Uid=cs245@jpgrady28;Port=1433;Pwd=C_plus_plus;encrypt=true;trustServerCertificate=false;hostNameInCertificate=*.database.windows.net;loginTimeout=30;");

    // open the connection
    bool ok = db.open();

        // if we connect successfully...
        if(ok)
        {
            // build the SQL string
            QString sql;
            sql += "UPDATE customer ";
            sql += "SET email = ?, city = ?, state = ? ";
            sql += "WHERE lastName = ?";

            // prepare the query
            QSqlQuery query;
            query.setForwardOnly(true);
            query.prepare(sql);

            // bind your values to the prepared statement
            query.bindValue(0, email);
            query.bindValue(1, city);
            query.bindValue(2, state);
            query.bindValue(3, lastName);

            // execute the UPDATE
            if(query.exec())
            {
                // display a message box
                QMessageBox::information(
                    this,
                    tr("Record Updated"),
                    tr("Your customer info was updated successfully!" )
                );
            }

            // Close the db
            db.close();
        }
        else {
            std::cout << "Issues" << std::endl;
        }
}
