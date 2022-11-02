//
//  main.cpp
//  PrimeStackFun
//
//  Created by Brandon Kamplain on 4/25/22.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "stackADT.h"
#include "linkedStack.h"
using namespace std;
using namespace chrono;

bool isPrime(long);

int main(int argc, const char * argv[]) {
    
    linkedStackType<long> stack;
    long num, temp, factor;
    
    cout << "Enter a positive number greater than 1\n";
    cin >> num;
    
    while(num <= 1)
    {
        cout << "You must enter a value greater than 1!! Let's try again, enter a number: ";
        cin >> num;
    }
    
    cout << "The prime factors of " << num << " are:\n";
    auto start = high_resolution_clock::now();
    
    if(isPrime(num))
    {
        cout << num << " is a prime number, its factors are: " << num << " and 1!\n";
        auto stop = high_resolution_clock::now();
        auto duration_ns = duration_cast<nanoseconds>(stop - start);
        auto duration_ms = duration_cast<milliseconds>(stop - start);
        duration_ns = duration_ns%1000000;
        cout << "\n\nTotal run time is: \n" << duration_ms.count() << " milliseconds and " << duration_ns.count() << " nanoseconds!\n";
        return 0;
    }
    
    stack.initializeStack();
    temp = num;
    
    while(temp > 1)
    {
        if(temp % 2 == 0)
        {
            stack.push(2);
            temp = temp/2;
        }
        else
            break;
    }
    factor = 3;
    
    while(temp > 1 && factor <= num/2)
    {
        if(!isPrime(factor))
            factor += 2;
        else if(temp % factor == 0)
        {
            stack.push(factor);
            temp = temp/factor;
        }
        else
            factor += 2;
    }
    
    cout << setfill(' ');
    //auto stop = high_resolution_clock::now();
    while(!stack.isEmptyStack())
    {
        cout << endl << setw(8) << stack.top();
        stack.pop();
    }
    
    auto stop = high_resolution_clock::now();
    auto duration_ns = duration_cast<nanoseconds>(stop - start);
    auto duration_ms = duration_cast<milliseconds>(stop - start);
    duration_ns = duration_ns%1000000;
    cout << "\n\nTotal run time is: \n" << duration_ms.count() << " milliseconds and " << duration_ns.count() << " nanoseconds!\n";
    
    return 0;
}

bool isPrime(long num)
{
    bool isPrimeNum;
    
    int sqrtNum, divisor = 3;
    
    if(num == 2)
        isPrimeNum = true;
    else if(num % 2 == 0)
        isPrimeNum = false;
    else
    {
        isPrimeNum = true;
        sqrtNum = static_cast<int>(pow(static_cast<double>(num), 0.5));
        
        while(divisor <= sqrtNum)
        {
            if(num % divisor == 0)
            {
                isPrimeNum = false;
                break;
            }
            divisor += 2;
        }
    }
    
    return isPrimeNum;
    
}
