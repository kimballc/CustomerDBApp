#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "customer.h"
#include <string>
#include <QtSql/QSqlDatabase>

class CustomerData
{

public:

    CustomerData();     // constructor
    ~CustomerData();    // destructor

    // get method
    Customer getCustomer() { return myCustomer; }

    // update a customer record in the database
    bool updateCustomer(const std::string &lastName,
             const std::string &email,
                        const std::string &city,
             const std::string &state);

private:

    Customer myCustomer;    // stores a single customer
    QSqlDatabase db;        // variable for database

    void loadCustomer();    // loads the customer record from the database

};

#endif // CUSTOMERDATA_H
