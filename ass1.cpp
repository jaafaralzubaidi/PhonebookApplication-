//Name: Jaafar Alzubaidi
//Class: CS300
//Task: Dynamic array 
#include <iostream>
#include "ContactsManager.h"


using namespace std;


int main(){
   cout << "MY PHONEBOOK APPLICATION" << endl;  
   ContactsManager m;
  


   char choice;
   string firstName, lastName, phoneNumber;
   
   cout << "Please choose an operation" << endl;
   cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";

   cin >> choice;
   
   
   while(choice != 'Q' && choice != 'q'){
   
      if(choice == 'A' || choice == 'a'){
         cout << "S (ADD)" << endl;
         //reding input from user
         cout << "First name: ";
         cin >> firstName;
         cin.ignore(20,'\n');

         cout << "Last name: ";
         cin >> lastName;
         cin.ignore(20,'\n');

         cout << "Phone number: ";
         cin >> phoneNumber;
         cin.ignore(20,'\n');
        
         m.appendContact(firstName, lastName, phoneNumber);
         firstName = lastName = phoneNumber = ""; 
      }
      else if(choice == 'S' || choice == 's'){
         cout << "S (Search)" << endl;
         //reding input from user
         cout << "Enter First Name: ";
         cin >> firstName;
         cin.ignore(20,'\n');

         cout << "Enter Last Name: ";
         cin >> lastName;
         cin.ignore(20,'\n');

         int index = m.search(firstName, lastName);
         if(index > -1)
            cout << m.getContact(index) << endl;
         else
            cout << "Contact is not found" << endl;
         
         firstName = lastName = phoneNumber = ""; 
      }
      else if(choice == 'D' || choice == 'd'){ 
         cout << "D (Delete)" << endl;
         //reding input from user
         cout << "Enter First Name: ";
         cin >> firstName;
         cin.ignore(20,'\n');

         cout << "Enter Last Name: ";
         cin >> lastName;
         cin.ignore(20,'\n');
         m.deleteContact(firstName, lastName);
         firstName = lastName = phoneNumber = ""; 
      }
      else if(choice == 'L' || choice == 'l'){
         cout << "L (List)" << endl;
         m.printAllContacts();
      }
      else 
         cout << "Wrong selection" << endl;
      
      cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
      cin >> choice;

  }
  cout << "Q (Quit)" << endl;

   return 0;
}

