#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "customer.h"
#include <string>
#include <QtSql/QSqlDatabase>
#include <vector>

class CustomerData
{

public:

    CustomerData();     // constructor
    ~CustomerData();    // destructor

    // get method
    Customer& getCustomer(int index) { return customers[index]; }
    std::vector<Customer>& getCustomers() {return customers;}

    // update a customer record in the database
    bool updateCustomer(int index, const std::string &lastName,
             const std::string &email,
                        const std::string &city,
             const std::string &state);

private:

    std::vector<Customer> customers;    // stores multiple customers
    QSqlDatabase db;        // variable for database

    void _loadCustomers();    // loads the customer record from the database

};

#endif // CUSTOMERDATA_H
