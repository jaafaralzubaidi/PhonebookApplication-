#include "ContactsManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


ContactsManager::ContactsManager(){
    arraySize = 10;
    numberOfContacts = 0;

    contactsPtr = new Contacts[arraySize];
    readInputFile();
}

//Reads the text file
void ContactsManager::readInputFile(){
    ifstream inputFileStream;
    inputFileStream.open("PhonebookShort.txt");

    string firstName, lastName, phoneNumber;

    if(inputFileStream.is_open()){
        
        while(inputFileStream.good()){
            inputFileStream >> firstName;
            inputFileStream >> lastName;
            inputFileStream >> phoneNumber;

            //if number of contacts is equal to the array size => double the array
            if(numberOfContacts == arraySize)
                doubleArraySize();

            // addContact(firstName, lastName, phoneNumber, contactsCount);
            addContact(firstName, lastName, phoneNumber, numberOfContacts);
            numberOfContacts++;
        }
        
    }
    else
         cout << "File didn't open" << endl;  

    inputFileStream.close();
}

//Doubles the arraySize
void ContactsManager::doubleArraySize(){
    arraySize = arraySize * 2;
    Contacts *tempArrayPtr = new Contacts[arraySize];

    for(int i = 0; i < arraySize/2; i++)
        tempArrayPtr[i] = contactsPtr[i];

    delete[] contactsPtr;
    contactsPtr = tempArrayPtr;

}

//Adds contacts at a specific index
void ContactsManager::addContact(string firstName, string lastName, string phoneNumber, int index){
    contactsPtr[index].setFirstName(firstName);
    contactsPtr[index].setLastName(lastName);
    contactsPtr[index].setPhoneNumber(phoneNumber);

}

//Prints contacts list
void ContactsManager::printAllContacts(){
    
    int size = numberOfContacts;
    
    for( int i = 0; i < size; i++){
        cout  << left << setw(4) << (i+1);
        cout << left << " " << setw(12) << contactsPtr[i].getFirstName(); 
        cout << left << " " << setw(12) << contactsPtr[i].getLastName();
        cout  << "  " << contactsPtr[i].getPhoneNumber()  << endl;
    }

}


//Adding a single contact to the end
void ContactsManager::appendContact(string firstName, string lastName, string phoneNumber){

    //if number of contacts is equal to the array size => double the array
    if(numberOfContacts == arraySize)
        doubleArraySize();

    //changing the names to upper case form
    stringToUpperCase(firstName); 
    stringToUpperCase(lastName);

    // addContact(firstName, lastName, phoneNumber, contactsCount);          
    addContact(firstName, lastName, phoneNumber, numberOfContacts);
    numberOfContacts++;
 
    cout << "Contact has been added" << endl;
}


//Convert a string to uppercase
void ContactsManager::stringToUpperCase(string &str){
    for(int i = 0; i < str.size(); i++)
        str[i] = toupper(str[i]);
}


//will return index of a contact and it will display contact
int ContactsManager::search(string firstName, string lastName){

    int size = numberOfContacts;
    stringToUpperCase(firstName);
    stringToUpperCase(lastName);

    //searching for a contact
    for(int i = 0 ; i < size; i++ ){
        if ( ( firstName == (contactsPtr[i].getFirstName()) ) && ( lastName == contactsPtr[i].getLastName()) )
            return i;
    }
    return -1;
}

//Returns a string of a contact
string ContactsManager::getContact(int index){
    return contactsPtr[index].getFirstName() +" "+ contactsPtr[index].getLastName()+ " " + contactsPtr[index].getPhoneNumber();
}


//Deletes a contact with first and last name
void ContactsManager::deleteContact(string firstName, string lastName){

    int index = search(firstName, lastName); 

    if(index > -1){
        Contacts * tempArrayPtr = new Contacts[arraySize];
    
        //copying all contacts to new a new temp array, last position
        for( int i = index; i < numberOfContacts; i++)
            contactsPtr[i] = contactsPtr[i+1];

        numberOfContacts--;
        cout << "Contact is deleted!" << endl;
    }else
        cout << "Contact is not found" << endl;  
}

ContactsManager::~ContactsManager(){
    delete [] contactsPtr;
    cout << "destructor" << endl;
}

int ContactsManager::getNumberOfContacts(){
    return numberOfContacts;
}
int ContactsManager::getArrayCapacity(){
    return arraySize;
}