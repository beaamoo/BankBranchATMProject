/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: bankBranch.h
DATE: Nov 22nd 2022
URL Repository: https://replit.com/@BeatriceMossber/FinalBankProgram#main.cpp
*****************************************************************/
// C++ code to implement an ATM and
// its basic functions
#include <fstream>
#include <iostream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "prePaidCard.h"


using namespace std;

#ifndef Included_BankBranch

#define Included_BankBranch

// Class PrePaidCard to get user and Card details

const int MAX_NUMBER_ACCOUNTS=10;

class BankBranch {
private:
  PrePaidCard client [MAX_NUMBER_ACCOUNTS]; //array of the prepaid card objects
  string name;
  int number_clients;
  int balance;
  string file; //default name of the file with the PrePaidCards
public:
// Member Functions
   BankBranch(); //V3.0 Constructor. It opens the file passed as argument
   BankBranch(string); //V3.0 Constructor. It asign a name to the Branch. File will be the name + ".txt"
   void loadClients(); //V2.0 It loads all clients from file aaa.txt
   void saveClients(); //V2.0 It saves the clients to a file aaa.txt
   int addUser(PrePaidCard p);
   PrePaidCard getClient(int);
   int addNewUser();
   int viewallUsers();
   int viewallCards();
   string getBankname();
   int deleteUser(int);
   void updateUserasdeposit(int);
   void updateUseraswithdraw(int);
   int searchSpecificUser(char*, int); //To be used by users
   int searchSpecificUser(char*); //To be used by Addmins. Don't need to know the password
   void setUserLoginDate (int); //To update last user login
   void displayUser(int);
   int debug();
   void blacklistUser(int);
   void checkPotentialLock(); 
   int deposited;
   int withdrawn;
   int changePass(int);

};

#endif
