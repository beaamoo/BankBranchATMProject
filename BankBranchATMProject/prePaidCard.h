/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: prePaidCard.h
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

using namespace std;

#ifndef Included_PrePaidCard

#define Included_PrePaidCard

// Class PrePaidCard to get user and Card details
class PrePaidCard {
private:
//adding attributes changes file sixe -> error
//delete txt file and add new one
    int card_ID;
    int ccv;
    int user_ID;
    int pin;
    int balance;
    int limit_negative;
    int interest_negative;
    time_t last_login;
    int number_failed_login;
        
    char username[30];
    int password;
    
  
public:
    void setLastLogin ();
    void setPassword (int);
    string getLastLogin ();
    int getFailedLogins();
    char* getUsername();
    int getPasswords();
    void getData();
    void showData(void);
    int getBalance();
    void deposit(int);
    void withdraw(int);
    int getCcv(void);
    int getCardID(void);
};
    

#endif
