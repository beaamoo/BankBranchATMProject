/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: bankBranch.cpp
DATE: Nov 22nd 2022
URL Repository: https://replit.com/@BeatriceMossber/FinalBankProgram#main.cpp
*****************************************************************/

#include "prePaidCard.h"
#include "bankBranch.h"

using namespace std;

//V3.0 Constructor. It opens the file passed as argument
BankBranch::BankBranch (string name_branch) 
{
  name=name_branch;
  file=name_branch+".txt";
}; 

//gets name of bank
string BankBranch::getBankname ()
    {
      return name;
    }

//V2.0
void BankBranch::loadClients()
{
    PrePaidCard a;
  
    ifstream file1;

    int i=0;
    number_clients=0;//V3 In case it is the first time we open the file
  
    // Open file in read mode
    file1.open(file, ios::in);
    if (!file1) {
        cout << "Error in opening file..";
        return 0;
    }
  
    // Read data from file
    file1.read((char*)&a, sizeof(a));
    while (!file1.eof()) {
  
        // Display data on monitor
        //a.showData(); 
        client[i]=a;
        i++;
        file1.read((char*)&a, sizeof(a));
    }
  
    // Close the file
    file1.close();
    number_clients=i;
    return 0;
}

void BankBranch::displayUser(int account_number)
{
  client[account_number].showData();
}

//V3
void BankBranch::setUserLoginDate (int account_number)
{
  client[account_number].setLastLogin();
}
  
// Function to add new user
int BankBranch::addNewUser()
{ 
    PrePaidCard newPrepaidCard;
    newPrepaidCard.getData();
    client[number_clients]=newPrepaidCard;
    number_clients++;
    return 0;
}
  
// View Users
int BankBranch::viewallUsers()
{
 if (number_clients==0) 
    cout<<"We still don't have any client :(\n";
 for (int i=0;i<number_clients;i++) {
    client[i].showData();
 }
 return 0;
}

// function to show locked cards
int BankBranch::viewallCards()
{
 if (number_clients==0) 
    cout<<"We still don't have any locked cards :(\n";
 for (int i=0;i<number_clients;i++) {
    cout<< "Card Number: " << i+1;
    cout<< ", Card Id: " << client[i].getCardID();
    cout<< ", Ccv: " << client[i].getCcv();
    cout<< ", Username: " << client[i].getUsername();
    cout<< ", Password: " << client[i].getPasswords()<<endl<<endl;  
 }
 return 0;
}


void BankBranch::saveClients()
{
    fstream temp;
    if (number_clients==0) //We still don't have any client
       return;
      
    temp.open("temp.txt",
              ios::out | ios::app);
    for (int i=0;i<number_clients;i++) {
      temp.write((char*)&client[i],sizeof(client[i]));
     }  
    // Close the file
    temp.close();
    remove(&file[0]);
    rename("temp.txt", &file[0]);
  
}


//Function to get a client PrePaidCard object
PrePaidCard BankBranch::getClient(int account_number) 
{
  return client[account_number];
}

//Function to add user
int BankBranch::addUser(PrePaidCard p) 
{    
  // add client to other BankBranch object
  client[number_clients]=p;
  // Update number of clients
  number_clients++;
  return 0;
}

// Function to delete the user
int BankBranch::deleteUser(int account_number)
{
    cout<<"Inside Remove User\n";
    client[account_number].showData();
    sleep(4);
  
    int client_size = sizeof(client) / sizeof(client[0]);

    // Delete the nth element from the client array
    memmove(client + account_number, client + account_number+1, (client_size - account_number -1) * sizeof(PrePaidCard));
  
    // Zero out the last element in the client array
    memset(client + client_size - 1, 0, sizeof(PrePaidCard));
    number_clients--;

    return 0;
}

// Function to update user by depositing money - WRITE FUNCTION
void BankBranch::updateUserasdeposit(int account_number)
{
  cout<<"Inside Update Deposit\n";
  client[account_number].showData();
  cout << "How much money would you like to deposit?";
  cin>> deposited;
  client[account_number].deposit(deposited);
  return 0;
}
  
// Function to update user by depositing withdrawing money - WRITE FUNCTION
void BankBranch::updateUseraswithdraw(int account_number)
{
  cout<<"Inside Withdraw\n"; 
  client[account_number].showData();
  cout << "How much money would you like to withdraw?";
  cin>> withdrawn;
  client[account_number].withdraw(withdrawn);
  return 0;
    
}
  
// Search user. Used by users
// Returns the account_number if user\password are correct
int BankBranch::searchSpecificUser(char* uname, int pass)
{
  for (int i=0;i<number_clients;i++) {
   if (!strcmp(client[i].getUsername(), uname)) {
            if (client[i].getPasswords() == pass) {
                return i;
              }  
     }
    } 
   return -1;//-1 Password incorrect
}

// Search user. Used by Admins
//V3. It returns the account_number 
int BankBranch::searchSpecificUser(char* uname)
{
  for (int i=0;i<number_clients;i++) {
   if (!strcmp(client[i].getUsername(), uname)) 
       return i;
    }     
   return -1;//-1 No user found
}

//V3.0 Help Debug the code. Information for BankBranch Object
int BankBranch::debug() 
{
  cout<<"BankBranch Attributes\n";
  cout<<"Name->"<<name<<" MAX_NUMBER_ACCOUNTS->"<<MAX_NUMBER_ACCOUNTS<<" number_clients->"<<number_clients<<" balance->"<<balance<<" file->"<<file<<endl;
  cout<<"\n***All Users Information***\n";
  viewallUsers();
  return 0;
}

// Function to change user password
int BankBranch::changePass(int account_number) 
{
  cout<<"Inside Change Password\n"; 
  cout<< "\nCurrent password: "<<client[account_number].getPasswords()<<endl;
  cout << "\nEnter new password (integers): ";
  int newPass;
  cin>> newPass;
  client[account_number].setPassword(newPass);
  return 0;
  
}

//Function to check potential cards that could be locked
void BankBranch::checkPotentialLock() 
{
  cout <<"\nSuggested cards to lock.\n";
  cout <<"Accounts with more than three failed logins:\n";
  int count=0;
  
  for (int i=0;i<number_clients;i++) {
    if (client[i].getFailedLogins()>3) {
      client[i].showData();
      count+=1;
    }  
  }
  if (count==0) {
    cout << "No accounts found.\n";
  }     
}




