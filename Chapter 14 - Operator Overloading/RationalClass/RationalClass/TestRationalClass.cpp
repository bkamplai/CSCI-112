//
//  TestRationalClass.cpp
//  RationalClass
//
//  Created by Brandon Kamplain on 2/22/22.
//

#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    // Create and initialize two rational numbers r1 and r2.
    Rational r1(2, 3);
    Rational r2(2, 3);

    // Test toString, add, subtract, multiply, and divide
    cout << r1.toString() << " + " << r2.toString() << " = " << r1.add(r2).toString() << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << r1.subtract(r2).toString() << endl;
    cout << r1.toString() << " * " << r2.toString() << " = " << r1.multiply(r2).toString() << endl;
    cout << r1.toString() << " / " << r2.toString() << " = " << r1.divide(r2).toString() << endl;

    // Test intValue and double
    cout << "r2.intValue()" << " is " << r2.intValue() << endl;
    cout << "r2.doubleValue()" << " is " << r2.doubleValue() << endl;

    // Test compareTo and equal
    cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
    cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
    cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
    cout << "r1.equals(r1) is " << (r1.equals(r1) ? "true" : "false") << endl;
    cout << "r1.equals(r2) is " << (r1.equals(r2) ? "true" : "false") << endl;

    cout << "r1 < r2: " << (r1.operator<(r2) ? "true" : "false") << endl;
    
    cout << "r1 < r2: " << (r1 < r2 ? "true" : "false") << endl;
    
    cout << "r2 < r1: " << (r2.operator<(r1) ? "true" : "false") << endl;
    
    cout << "r2 < r1: " << (r2 < r1 ? "true" : "false") << endl;


    double d = r1 + 5.1;
    cout << "r1 + 5.1 is " << d << endl;
    cout << r1 << " + 5.1 is " << d << endl;

    //Rational r = r1 + 4;
    //Rational r = 4 + r1; // Automatically converting 4 to Rational
    //cout << r << endl;
    
    return 0;
}
