#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class BankManagementSystem
{
private:
  double balance;
  string accountHolderName;
  int accountNumber;

public:
  // constructor
  BankManagementSystem(double b, string n, int a) : balance(b), accountHolderName(n), accountNumber(a) {}

  // function to deposit amount in account
  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited Rs." << amount << 'successfully' << endl;
  }

  // function to withdraw amount
  void withdraw(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;
      cout << "Withdrawl of Rs." << amount << "successful." << endl;
    }
    else
    {
      cout << "Insufficient funds" << endl;
    }
  }

  // display all the user info
  void display()
  {
    cout << "Account Number:" << accountNumber << endl;
    cout << "Account Holder Name:" << accountHolderName << endl;
    cout << "Balance:" << balance << endl;
  }

  // function to get account Number
  int getAccountNumber()
  {
    return accountNumber;
  }
};

class Bank
{
private:
  vector<BankManagementSystem> accounts;

public:
  // function to add accounts
  void addAccount(BankManagementSystem account)
  {
    accounts.push_back(account);
    cout << "Account added successfully." << endl;
  }

  // display all the accounts
  void displayAllAccounts()
  {
    for (int i = 0; i < accounts.size(); i++)
    {
      accounts[i].display();
      cout << endl;
    }
  }

  // withdraw validation
  int withdraw(int a, int m)
  {
    for (int i = 0; i < accounts.size(); i++)
    {
      if (accounts[i].getAccountNumber() == a)
      {
        accounts[i].deposit(m);
        return 1;
      }
    }
    cout << "Account Number not found" << endl;
    return -1;
  }

  // deposit
  int deposit(int accountNumber, int amount)
  {
    for (int i = 0; i < accounts.size(); i++)
    {
      if (accounts[i].getAccountNumber() == accountNumber)
      {
        accounts[i].deposit(amount);
        return 1;
      }
    }
    cout << "Account number not found" << endl;
    return -1;
  }
};
int main()
{
  Bank X;
  int choice;
  do
  {
    cout << "1.Add account" << endl;
    cout << "2.Display all the accounts" << endl;
    cout << "3.Deposit money" << endl;
    cout << "4.Withdraw money" << endl;
    cout << "5.exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      int accountNumber;
      string name;
      double balance;
      cout << "Enter account number:";
      cin >> accountNumber;
      cout << "Enter account holder name:";
      cin.ignore();
      getline(cin, name);
      cout << "Enter initial balance:";
      cin >> balance;
      BankManagementSystem newAccount(balance, name, accountNumber);
      X.addAccount(newAccount);
      break;
    }
    case2:
    {
      X.displayAllAccounts();
      break;
    }
    case 3:
    {
      int accountNumber;
      double amount;
      cout << "Enter account Number:" << endl;
      cin >> accountNumber;
      cout << "Enter deposit amount:" << endl;
      cin >> amount;
      X.deposit(accountNumber, amount);
      break;
    }
    case 4:
    {
      int accountNumber;
      double amount;
      cout << "Enter account number:";
      cin >> accountNumber;
      cout << "Enter the withdrawl amount:";
      cin >> amount;
      X.withdraw(accountNumber, amount);
    }

    default:

      cout << "Invalid choice!!";
    }
  } while (choice != 5);

  return 0;
}