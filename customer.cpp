#include "customer.h"
#include <string>
using std::string;

/*
 *  Constructors
 */
Customer::Customer() { }

Customer::Customer(int customerId = 0,
                   const string &firstName = "N/A",
                   const string &lastName = "N/A",
                   const string &email = "N/A",
                   const string &homeTown = "Waterville",
                   const string &homeState = "ME")
    : customerId(customerId), firstName(firstName), lastName(lastName),
      email(email), homeTown(homeTown), homeState(homeState)
{

}

// sets customer id
void Customer::setCustomerId(unsigned id)
{
    this->customerId = id;
}


// sets first name
void Customer::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}


// sets last name
void Customer::setLastName(const string &lastName)
{
    this->lastName = lastName;
}


// sets email
void Customer::setEmail(const std::string &email)
{
    this->email = email;
}


// sets home town
void Customer::setHomeTown(const std::string &homeTown)
{
    this->homeTown = homeTown;
}


// sets home state
void Customer::setHomeState(const std::string &homeState)
{
    this->homeState = homeState;
}
