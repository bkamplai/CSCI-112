//
//  checkingAccount.h
//  Week5
//
//  Created by Brandon Kamplain on 2/24/22.
//

#ifndef checkingAccount_h
#define checkingAccount_h
#include "bankAccount.h"
#include <stdio.h>
const double CHECKING_INTEREST_RATE = 0.01;

class checkingAccount : public bankAccount
{
public:
    checkingAccount(int acctNumber, double bal, double intRate = CHECKING_INTEREST_RATE);
    void setInterestRate(double rate);
    double getInterestRate()const;
    void setMinBal(double minBal);
    double getMinBal()const;
    void setServiceCharge(double fine);
    double getServiceCharge()const;
    void postInterest();
    bool verifyMinBal(double acct, double minBal);
    void writeCheck(double amount);
    void withdraw(double amount);
    void print() const;
protected:
    double interestRate;
    double minimumBalance;
    double serviceCharge;
};

#endif /* checkingAccount_h */
