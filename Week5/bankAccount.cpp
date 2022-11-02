//
//  bankAccount.cpp
//  Week5
//
//  Created by Brandon Kamplain on 2/23/22.
//

#include "bankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

bankAccount::bankAccount(int acctNumber, double bal)
{
    accountNumber = acctNumber;
    balance = bal;
}

void bankAccount::setAccountNumber(int acct)
{
    accountNumber = acct;
}

double bankAccount::getBalance() const
{
    return balance;
}

int bankAccount::getAccountNum() const
{
    return accountNumber;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::withdraw(double amount)
{
    if (balance>=amount)
        balance -= amount;
    else
        cout << "Sorry, insuficcient funds...let's face it, you broke..\n";
}

void bankAccount::print() const
{
    cout << fixed << setprecision(2);
    cout << "Your account: " << accountNumber << " Balance is: " << balance;
}
