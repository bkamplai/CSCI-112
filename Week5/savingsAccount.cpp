//
//  savingsAccount.cpp
//  Week5
//
//  Created by Brandon Kamplain on 2/24/22.
//

#include "savingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

savingsAccount::savingsAccount(int acctNumber, double bal, double intRate):bankAccount(acctNumber, bal)
{
    interestRate = intRate;
}

double savingsAccount::getInterestRate()const
{
    return interestRate;
}

void savingsAccount::setInterestRate(double rate)
{
    interestRate = rate;
}

void savingsAccount::withdraw(double amount)
{
    if (balance - amount < 0)
        cout << "Sorry not enough moeny in your account.." << endl;
    else
        balance -= amount;
}

void savingsAccount::postInterest()
{
    balance += balance * interestRate;
}

void savingsAccount:: print() const
{
    cout << fixed << setprecision(2);
    cout << "Your savings account #:\t\t\t" << getAccountNum() << "\tBalance is: $" << getBalance() << endl;
}
