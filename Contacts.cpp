#include <iostream>
#include "Contacts.h"

using namespace std;


Contacts::Contacts(){
}

void Contacts::setFirstName(string name){
    firstName = name;
}
void Contacts::setLastName(string name){
    lastName = name;
}
void Contacts::setPhoneNumber(string number){
    phoneNumber = number;
}

string Contacts::getFirstName(){
    return firstName;
}
string Contacts::getLastName(){
    return lastName;
}
string Contacts::getPhoneNumber(){
    return phoneNumber;
}



