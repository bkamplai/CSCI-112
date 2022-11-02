//
//  savingsAccount.h
//  Week5
//
//  Created by Brandon Kamplain on 2/23/22.
//

#ifndef savingsAccount_h
#define savingsAccount_h
#include "bankAccount.h"
#include <stdio.h>
const double DEFAULT_INTEREST_RATE = 0.06;

class savingsAccount : public bankAccount
{
public:
    savingsAccount(int acctNumber, double bal, double intRate = DEFAULT_INTEREST_RATE);
    void setInterestRate(double rate);
    double getInterestRate()const;
    void postInterest();
    void withdraw(double amount);
    void print() const;
protected:
    double interestRate;
    
};

#endif /* savingsAccount_h */
