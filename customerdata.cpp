#include "customerdata.h"
#include "customer.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/*
 * Constructor
 */
CustomerData::CustomerData()
{
    // create a database connection object
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=jpgrady28.database.windows.net;Database=restaurant;Uid=cs245@jpgrady28;Port=1433;Pwd=C_plus_plus;encrypt=true;trustServerCertificate=false;hostNameInCertificate=*.database.windows.net;loginTimeout=30;");

    // load the customer info from the database
    this->loadCustomer();
}

/*
 * destructor
 */
CustomerData::~CustomerData()
{
          db.close();
}



// load the customer from the database
void CustomerData::loadCustomer()
{

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

                    /*
                     *  NOTE: toString() returns a QString object, not a std::string
                     *  Use the QString.toStdString() command to convert the QString
                     *  to a std::string.
                     */

                    // Get the remaining data from the result set
                    unsigned customerId = query.value(0).toInt();
                    string firstName = query.value(1).toString().toStdString();
                    string lastName = query.value(2).toString().toStdString();
                    string email = query.value(3).toString().toStdString();
                    string city = query.value(4).toString().toStdString();
                    string state = query.value(5).toString().toStdString();

                    // Store the data in the Customer data member
                    myCustomer.setCustomerId(customerId);
                    myCustomer.setFirstName(firstName);
                    myCustomer.setLastName(lastName);
                    myCustomer.setEmail(email);
                    myCustomer.setHomeTown(city);
                    myCustomer.setHomeState(state);
                 }
             }

        }
        else {
            std::cout << "Issues" << std::endl;
        }
}


// update a customer record in the database
bool CustomerData::updateCustomer(const string &lastName, const string &email, const string &city, const string &state)
{
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
            query.bindValue(0, QString::fromStdString(email));
            query.bindValue(1, QString::fromStdString(city));
            query.bindValue(2, QString::fromStdString(state));
            query.bindValue(3, QString::fromStdString(lastName));

            // execute the UPDATE
            if(query.exec())
            {
                return true;
            }

        } else {
            return false;
        }

    return false;
}

