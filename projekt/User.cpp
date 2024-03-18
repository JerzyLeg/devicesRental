#include "User.h"
#include <iostream>
using namespace std;
User::User(string username, string email)
{  
    this->username_ = username;
    this->email_ = email;
    this->generateID();
}

string User::toString()
{
    return "username: " + this->username_ + " email: " + this->email_;
}

size_t User::getID()
{
    return this->ID;
}


string User::toCSV()
{
    return this->username_ + "," + this->email_;
}


string& User::username()
{
    return this->username_;
}

string& User::email()
{
    return this->email_;
}


void User::generateID()
{
    auto tmp = std::hash<std::string>{}(this->toString());
    this->ID = tmp;
    cout << "userID: " << tmp << endl;
}
