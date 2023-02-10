/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: functions.cpp
DATE: Nov 22nd 2022
URL Repository: https://replit.com/@BeatriceMossber/FinalBankProgram#main.cpp
*****************************************************************/
//external functions outside of classes driving user interface
#include <fstream>
#include <iostream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include "bankBranch.h"
using namespace std;


void atmUser()
{
    BankBranch aa ("Madrid"); //implement pointer
    BankBranch bb ("Valencia");
    BankBranch cc ("Segovia");

    //Store data of blacklisted and locked cards as bank branch object -> to be able to reuse functions
    BankBranch bl ("Blacklist"); //pointer to blacklist
    BankBranch lc ("LockedCards"); //pointer to locked cards
  
    BankBranch *pBB=NULL; //decalring pointer to the bankBranch
    
  //implement choice for admin to log into specififc branch
    int bankChoice;

    cout<<"1. Madrid"<<endl<<"2. Valencia"<<endl<<"3. Segovia"<<endl<<"Enter your bank branch:";
    cin>> bankChoice;
    
    switch (bankChoice) {
      case 1:
        pBB=&aa; //assign pointer to aa=MadridBranch
        break;
       
      case 2: 
        pBB=&bb;
        break;
      
      case 3: 
        pBB=&cc;
        break;
      }
  
    char uname[30];
    int accNum;
    PrePaidCard copied_client;
    int pass, ch, ch1, ch2, ch3, ch4, found = 0;

    cout<<"*****BankBranch Information*****\n";
    pBB->loadClients(); //pointer to which branch instead of directly going to branch -> use pointer (*pBB) or pBB-> instead of aa
    pBB->debug(); //V3 Debug example
    sleep(5);
  
  
mainmenu:
  
    system("clear");
    cout << "\nWelcome to the " << (*pBB).getBankname()<<" bank branch";
    cout << "\nLogin as :\n1. Admin\n2."
         << " User\n3. "
            "Exit\nChoose one : ";
    cin >> ch;
  
    switch (ch) {
    case 1:
    rerun:
        system("clear");
        cout << "\nEnter details to"
             << " login as Admin\n";
        cout << "\nEnter password:";
        cin >> pass;
        if (pass == 1234) {
        admin:
            system("clear");
            cout << "\nWelcome to"
                 << " Admin Menu";
            cout << "\n1. Add User\n2."
                 << " Delete User\n3. "
                    "View All User\n4. "
                    "Blacklist\n5. "
                    "Lock/Unlock Card\n6. "
                 << "Exit and save Client Details";
            cout << "\nSelect one : ";
            cin >> ch1;
            switch (ch1) {
            case 1:
                (*pBB).addNewUser();
                goto admin;
  
            case 2:
                cout << "\nEnter the "
                     << "username to be "
                        "deleted : ";
                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n');
                cin.getline(uname, 30);
                
                // returns account number
                accNum=(*pBB).searchSpecificUser(uname);
                //delestes user from client array
                (*pBB).deleteUser(accNum);
                sleep(4);
                goto admin;
  
            case 3:
                (*pBB).viewallUsers();
                sleep(10);
                goto admin;
            
            case 4:
                // the blacklist is contained in a similar file as a bank branch, to be used by all banks and prevent fraud
                bl.loadClients();
                //blacklist menu
                blacklist:
                    system("clear");
                    cout << "\n1. View Blacklist \n2."
                       << " Blacklist User\n3."
                          " Remove User from Blacklist\n4."
                       << " Exit and save Blacklist";
                    cout << "\nSelect one : ";
                    cin >> ch3;
                    switch (ch3) {
                    case 1:
                        //display current blacklist
                        cout<<"*****Blacklist Information*****\n\n";
                        bl.viewallUsers();
                        sleep(4);
                        goto blacklist;
                      
                    case 2:
                        // add user to blacklist
                        cout << "\nEnter the "
                             << "username to be "
                                "put on blacklist : ";
                        cin.ignore(
                            numeric_limits<streamsize>::max(),
                            '\n');
                        cin.getline(uname, 30);
                        // returns account number
                        accNum=(*pBB).searchSpecificUser(uname);
                        //add user from bankbranch to blacklist
                        
                        copied_client=pBB->getClient(accNum);
                        bl.addUser(copied_client);
                        
                        cout << "\nUser has been blacklisted.\n";
                        sleep(4);
                        goto blacklist;
                      
                    case 3:
                        // remove user from blacklist
                        cout << "\nEnter the "
                            << "username to be "
                                "removed from blacklist : ";
                        cin.ignore(
                            numeric_limits<streamsize>::max(),
                            '\n');
                        cin.getline(uname, 30);
                          
                        // returns account number
                        accNum=(*pBB).searchSpecificUser(uname);
                        //delete user from blacklist
                        bl.deleteUser(accNum);
                        sleep(4);
                        goto blacklist;
                        
                    case 4:
                        bl.saveClients();
                        break;
                      }
                goto admin;

            case 5:
                // the lockcard list is contained in a similar file as a bank branch, to be used by all banks and prevent fraud
                lc.loadClients();
                //lock card menu
                lockcard:
                    system("clear");
                    cout << "\n1. View Locked Cards \n2."
                       << " Lock Card\n3."
                          " Unlock Card\n4."
                       << " Exit and Save Locked Cards";
                    cout << "\nSelect one : ";
                    cin >> ch4;
                    switch (ch4) {
                    case 1:
                        //display current users with locked cards
                        cout<<"*****Locked Cards Information*****\n\n";
                        lc.viewallCards();
                        sleep(4);
                        goto lockcard;
                      
                    case 2:
                        pBB->checkPotentialLock();
                        // add user to lockcard
                        cout << "\nEnter the "
                             << "username to  "
                                "lock card : ";
                        cin.ignore(
                            numeric_limits<streamsize>::max(),
                            '\n');
                        cin.getline(uname, 30);
                        // returns account number
                        accNum=(*pBB).searchSpecificUser(uname);
                        //add user from bankbranch to lockcards
                        copied_client=pBB->getClient(accNum);
                        lc.addUser(copied_client);
                        
                        cout << "\nCard has been locked.\n";
                        sleep(4);
                        goto lockcard;
                      
                    case 3:
                        // remove user from lockcard
                        cout << "\nEnter the "
                            << "username to "
                                "unlock card : ";
                        cin.ignore(
                            numeric_limits<streamsize>::max(),
                            '\n');
                        cin.getline(uname, 30);
                          
                        // returns account number
                        accNum=(*pBB).searchSpecificUser(uname);
                        //delete user from lockcard
                        lc.deleteUser(accNum);
                        cout << "The user has been removed.";
                        sleep(4);
                        goto lockcard;
                        
                    case 4:
                        lc.saveClients();
                        break;
                      }
              
                goto admin;

            case 6:
              //save client details
              (*pBB).saveClients(); 
              break;
            }
        }
        else {
            cout << "\nDetails are "
                 << "incorrect ! Please"
                    " try again";
            cin.get();
            goto rerun;
        }
        goto mainmenu;

      
  //User menu
    case 2:
        cout << "\n Enter details to"
             << " login as User\n";
  
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');
        cout << "Enter username:";
        cin.getline(uname, 30);
        cout << "\nEnter password:";
  
        cin >> pass;
        found = (*pBB).searchSpecificUser(uname, pass);
          
        if (found!=-1) {
        user:
            system("clear");
            (*pBB).setUserLoginDate(found);
            cout << "\nWelcome "
                 << uname;
            cout << "\nWelcome to"
                 << " User Menu";
            cout << "\n1. Deposit\n2."
                 << " Withdraw\n3. View "
                    "Account\n4. Change Password\n5. "
                 << "Exit and Save\nEnter your choice:";
            cin >> ch2;
  
            switch (ch2) {
            case 1:
                (*pBB).updateUserasdeposit(found);
                sleep(4);
                goto user;
            case 2:
                (*pBB).updateUseraswithdraw(found);
                sleep(4);
                goto user;
            case 3:
                (*pBB).displayUser(found);
                sleep(4);
                goto user;
            case 4:
                (*pBB).changePass(found);
                cout <<"Password has been changed.";
                sleep(4);
                goto user;
            case 5:
                (*pBB).saveClients();
                cout << "Thank you";
                break;  
              
            }
        }
        else {
            cout << "\nNo account found"
                 << " with username "
                    ":(\n\nHit ENTER to continue "
                 << uname;
            cin.get();
        }
        goto mainmenu;
  
    case 3:
        cout << "\nThank you for using the best ATM";
        (*pBB).saveClients();  
        cin.get();
        break;
    }
}