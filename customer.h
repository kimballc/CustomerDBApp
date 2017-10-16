#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{

public:

    // Constructors
    Customer();
    Customer(int customerId,
             const std::string &firstName,
             const std::string &lastName,
             const std::string &email,
             const std::string &homeTown,
             const std::string &homeState);

    //=======================================================
    // "get" method definitions
    //=======================================================

    unsigned getCustomerId() { return customerId; }
    std::string getFirstName() { return firstName; }
    std::string getLastName() { return lastName; }
    std::string getEmail() { return email; }
    std::string getHomeTown() { return homeTown; }
    std::string getHomeState() { return homeState; }


    //=======================================================
    // "set" method declarations
    //=======================================================

    void setCustomerId(unsigned);
    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setEmail(const std::string &);
    void setHomeTown(const std::string &);
    void setHomeState(const std::string &);


private:

    // Data members
    unsigned customerId;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string homeTown;
    std::string homeState;
};

#endif // CUSTOMER_H
