/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: prePaidCard.cpp
DATE: Nov 22nd 2022
URL Repository: https://replit.com/@BeatriceMossber/FinalBankProgram#main.cpp
*****************************************************************/
#include "prePaidCard.h"

void PrePaidCard::setLastLogin ()
    {
       last_login = time(0);
    }
//Function to set new password
void PrePaidCard::setPassword (int newPass)
    {
       password = newPass;
    }

string PrePaidCard::getLastLogin ()
    {
      char* dt = ctime(&last_login);   // convert in string form
      return dt;
    }

int PrePaidCard::getFailedLogins()
{
  return number_failed_login;
};

char* PrePaidCard::getUsername(void)
    {
        // Return username
        return username;
    }
  
int PrePaidCard::getPasswords(void)
    {
        // Return the password
        return password;
    }

int PrePaidCard::getBalance(void)
    {
        // Return the balance
        return balance;
    }

int PrePaidCard::getCardID(void)
    {
        // Return the balance
        return card_ID;
    }
int PrePaidCard::getCcv(void)
    {
        // Return the balance
        return ccv;
    }
  
// Function to get the data
void PrePaidCard::getData(void)
    {
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');
        cout << "\nEnter username:";
  
        cin.getline(username, 30);
        cout << "\nEnter 4-digit "
             << "password:";
  
        cin >> password;
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');
        cout << "\nEnter initial"
             << " balance:";
  
        cin >> balance;
        setLastLogin();
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');
    }
  
// Function displaying the data
void PrePaidCard::showData(void)
    {
        cout << "Username:" << username
             << ", Password:" << password
             << ", Balance:" << balance
             << ", Last Login:" << getLastLogin()
             << endl;
    }
void PrePaidCard::deposit(int money){
  balance += money;
}

void PrePaidCard::withdraw(int money){
  balance -= money;
}

    