//
//  checkingAccount.cpp
//  Week5
//
//  Created by Brandon Kamplain on 2/25/22.
//

#include "checkingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

checkingAccount::checkingAccount(int acctNumber, double bal, double intRate):bankAccount(acctNumber, bal)
{
    interestRate = intRate;
}

bool checkingAccount::verifyMinBal(double acct, double minBal)
{
    if (balance < minimumBalance)
    {
        cout << "Your balance is below the minimum balance of $" << minBal << endl;
        return true;
    }
    else
        return false;
}

void checkingAccount::writeCheck(double amount)
{
    withdraw(amount);
}

double checkingAccount::getInterestRate()const
{
    return interestRate;
}

void checkingAccount::setInterestRate(double rate)
{
    interestRate = rate;
}

void checkingAccount::setMinBal(double minBal)
{
    minimumBalance = minBal;
}

double checkingAccount::getMinBal()const
{    return minimumBalance;
}

void checkingAccount::setServiceCharge(double fine)
{
    serviceCharge = fine;
    /*
    if (balance < 0)
        serviceCharge += fine;
    */
}

double checkingAccount::getServiceCharge()const
{
    return serviceCharge;
}

void checkingAccount::withdraw(double amount)
{
    if (balance - amount < 0)
        cout << "Sorry not enough moeny in your account.." << endl;
    else
        balance -= amount;
}

void checkingAccount::postInterest()
{
    balance += balance * interestRate;
}

void checkingAccount:: print() const
{
    cout << fixed << setprecision(2);
    cout << "Your checking account #:\t\t\t" << getAccountNum() << "\tBalance is: $" << getBalance() << endl;
}
