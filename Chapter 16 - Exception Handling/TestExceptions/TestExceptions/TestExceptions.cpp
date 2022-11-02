//
//  TestExceptions.cpp
//  TestExceptions
//
//  Created by Brandon Kamplain on 4/1/22.
//

#include <iostream>
#include <stdexcept>
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
using namespace std;

double getArea(double radius)
{
    if (radius < 0)
    {
        throw invalid_argument("Radius cannot be negative");
    }
    
    return radius * radius * 3.14159;
}

int quotient(int num1, int num2)
{
    if (num2 == 0)
    {
        throw runtime_error("divisor connot be zero");
    }
    return num1/num2;
}

int main()
{
    try
    {
        for (int i =1; i<=502490; i++)
        {
            new int[70000000];
            cout << i << " arrays have been created" << endl;
        }
    }
    catch(bad_alloc& ex)
    {
        cout << "Exception: " << ex.what() << endl;
    }
    
    cout << "execution continues\n";
    
    return 0;
}
