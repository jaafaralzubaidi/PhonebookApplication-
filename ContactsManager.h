#pragma once
#include "Contacts.h"
#include <iostream>
using namespace std;

class ContactsManager{
private:

    Contacts * contactsPtr;
    int arraySize;
    int numberOfContacts;
    void addContact(string , string , string , int );


public:
    ContactsManager();
    void readInputFile();
    void doubleArraySize();
    void printAllContacts();
    void appendContact(string, string, string);
    void stringToUpperCase(string&);
    int search(string, string);
    string getContact(int);
    void deleteContact(string, string);
    ~ContactsManager();
    int getNumberOfContacts();
    int getArrayCapacity();
    

};