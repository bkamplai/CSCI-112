//
//  week6.cpp
//  week6
//
//  Created by Brandon Kamplain on 3/2/22.
//

#include <iostream>
#include <ctime>
using namespace std;

int sum(int);
void sumOfNums(int);
long long int fib(long long int n);
void fibonacciSequence(int);
int test(int, int);
int func(int);
void typicalExaminationQuestions();
void recursiveTowers(int, int, int, int);
void iterativeTowers(int, int, int, int);
void challenge();
char Menu();
char challengeMenu();

int main()
{
    int n;
    char Choice;
        while(1){
            Choice = Menu();
            switch(Choice){
                case '1': sumOfNums(n); break;
                case '2': fibonacciSequence(n); break;
                case '3': typicalExaminationQuestions(); break;
                case '4': challenge(); break;
                case '5': break;
                default: cout << "Invalid choice!\n\n";
            }
            if (Choice=='5') break;
        }

    return 0;
}

char Menu()
{
    char Option[20];
    cout << "*** Practicum: Week 6 ***\n\n";
    cout << "1. Sum of Numbers\n";
    cout << "2. Fibonacci Sequence\n";
    cout << "3. Typical Exam Questions (see code)\n";
    cout << "4. Tower of Hanoi\n";
    cout << "5. Exit from the system\n";
    cout << "Enter your choice (1..5): ";
    cin.getline(Option,20);
    cout<<endl;
    return Option[0];
}

int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n-1);
        
}

void sumOfNums(int n)
{
    //int n;
    cout << "\nEnter n: ";
    cin >> n;
    
    if (n < 1)
    {
        cout << "Please enter an integer greater than or euqal to 1. Exiting...\n";
        exit(1);
    }
    
    cout << "\nThe sum from 1 to " << n << " is: " << sum(n) << endl << endl;
}

void fibonacciSequence(int n)
{
    clock_t begin, end;

    //int n;
    cout << "\nEnter n: ";
    cin >> n;
    
    begin = clock();
    cout << "\nThe fibonacci of " << n << " is " << fib(n) << endl;
    end = clock();
    
    cout << "\nTime it took (in sec's) to generate number: " << (end-begin)/CLOCKS_PER_SEC << endl << endl;
    //Running the fib(10) is almost instant, but running fib(50) takes considerable time, for me took about over a minuet to complete.
}

long long int fib(long long int n)
{
    if (n < 2)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

void typicalExaminationQuestions()
{
    // Result: 15
    // Actual result: 15
    cout << "\ntest(5, 10) = "<< test(5,10) << endl;
    // Result: 6
    // Actual result: 6
    cout << "\ntest(3, 9) = "<< test(3,9) << endl;
    
    /* My Results:
     func(0) = 2
     func(1) = 3
     func(2) = 5
     func(5) = 21
     */
    
    cout << "\nfunc(0) = " << func(0) << endl;
    cout << "\nfunc(1) = " << func(1) << endl;
    cout << "\nfunc(2) = " << func(2) << endl;
    cout << "\nfunc(5) = " << func(5) << endl << endl;

     /* Actual Results:
      func(0) = 2
      func(1) = 3
      func(2) = 5
      func(5) = 21
      */
}

int test(int x, int y)
{
    if (x==y)
        return x;
    else if (x>y)
        return x+y;
    else
        return test(x+1, y-1);
}

int func(int x)
{
    if (x==0)
        return 2;
    else if (x==1)
        return 3;
    else
        return (func(x-1) + func(x-2));
}

char challengeMenu()
{
    char Option[20];
    cout << "*** Towers of Hanoi ***\n\n";
    cout<<"Enter :\n";
    cout<<"1 : for Recursive Solution\n";
    cout<<"2 : for Iterative Solution\n";
    cout<<"5 : to quit\n";
    
    cout<<"Which solution : ";
    cin.getline(Option,20);
    cout<<endl;

    return Option[0];
}

void challenge()
{
    int n=9, source=1, destn=3, transfer=2;
    
    char Choice;
        while(1){
            Choice = challengeMenu();
            switch(Choice){
                case '1': recursiveTowers(n, source, destn, transfer); break;
                case '2': iterativeTowers(n, source, destn, transfer); break;
                case '5': break;
                default: cout << "Invalid choice!\n\n";
            }
            if (Choice=='5') break;
        }
    

}

void recursiveTowers(int n, int source, int destn, int transfer)
{
    if (n > 1)
        recursiveTowers(n-1, source, transfer, destn);
    cout << "Move ring " << n << " from peg " << source << " to peg " << destn << ".\n";
    if (n > 1)
        recursiveTowers(n-1, transfer, destn, source);
}

void iterativeTowers(int n, int source, int destn, int transfer)
{
    while (n >= 1)
    {
        int temp;
        if (n>1)
        {
            n--;
            temp = transfer;
            transfer = destn;
            destn = temp;
        }
        
        cout << "Move ring " << n << " from peg " << source << " to peg " << destn << ".\n";
        
        if (n>1)
        {
            int temp2 = source;
            source = temp;
            destn = transfer;
            transfer = temp2;
        }
        n--;
    }
}
