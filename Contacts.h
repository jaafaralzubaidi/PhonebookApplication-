#pragma once
#include <iostream>

using namespace std;

class Contacts{

private:
    string firstName, lastName, phoneNumber;


public:
    Contacts();
    void setFirstName(string);
    string getFirstName();
    void setLastName(string);
    string getLastName();
    void setPhoneNumber(string);
    string getPhoneNumber();
    void setNumberOfContacts(int n);
    int getNumberOfContacts();


};