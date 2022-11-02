//
//  main1.cpp
//  Week2
//
//  Created by Brandon Kamplain on 2/3/22.
//

#include <iostream>

using namespace std;

void findSmallest(int* , int* , int* );

int main(int argc, const char * argv[]) {
    
    if (argc != 4)
    {
        cout<<"\nIncorrect number of arguments. USAGE: ./main1 num1 num2 num3. Exiting...\n\n";
        exit(1);
    }
    
    //int A, B, C;
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    
    findSmallest(&a, &b, &c);
    
    return 0;
}

void findSmallest(int* a, int* b, int* c)
{
    int A, B, C, num1, num2, num3;
    
    num1 = *a;
    num2 = *b;
    num3 = *c;
    

    if (num1<num2 && num1<num3)
    {
        A = num1;
    }
    else if (num2<num1 && num2<num3)
    {
        A = num2;
    }
    else
    {
        A = num3;
    }

    
    if (num1>num2 && num1<num3)
    {
        B = num1;
    }
    else if (num1<num2 && num1>num3)
    {
        B = num1;
    }
    else if (num2<num1 && num2>num3)
    {
        B = num2;
    }
    else if (num2>num1 && num2<num3)
    {
        B = num2;
    }
    else
    {
        B = num3;
    }
    
    

    if (num1>num2 && num1>num3)
    {
        C = num1;
    }
    else if (num2>num1 && num2>num3)
    {
        C = num2;
    }
    else
    {
        C = num3;
    }

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
}

