//
//  main.cpp
//  Chapter 14 Programming Project 1
//
//  Created by Brandon Kamplain on 5/7/22.
//

// Search for "WRITE YOUR CODE" to complete this program
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(double a, double b);
    Complex(double a);
    double getRealPart() const;
    double getImaginaryPart() const;
    Complex add(const Complex& secondComplex) const;
    Complex subtract(const Complex& secondComplex) const;
    Complex multiply(const Complex& secondComplex) const;
    Complex divide(const Complex& secondComplex) const;
    double abs() const;
    string toString() const;
    
    Complex& operator+=(Complex& secondComplex);
    Complex& operator-=(Complex& secondComplex);
    Complex& operator*=(Complex& secondComplex);
    Complex& operator/=(Complex& secondComplex);
    
    double& operator[](const int&  index);
    
    Complex& operator++(); // Prefix ++
    Complex& operator--(); // Prefix --
    
    Complex operator++(int dummy); // Postfix ++
    Complex operator--(int dummy); // Postfix --
    
    Complex operator+(); // Unary +
    Complex operator-(); // Unary -
    
    friend ostream& operator<<(ostream& stream, const Complex& complex);
    friend istream& operator >> (istream& stream, Complex& complex);
    
private:
    double a;
    double b;
};

// Non-member operator functions
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);

bool operator<(const Complex& c1, const Complex& c2);
bool operator<=(const Complex& c1, const Complex& c2);
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);
bool operator>(const Complex& c1, const Complex& c2);
bool operator>=(const Complex& c1, const Complex& c2);


// WRITE YOUR CODE to implement the Complex class here

int main()
{
    Complex number1;
    cout << "Enter the first complex number: ";
    cin >> number1;
    
    Complex number2;
    cout << "Enter the second complex number: ";
    cin >> number2;
    
    cout << "(" << number1 << ")" << " + " << "(" << number2
    << ") = " << (number1 + number2) << endl;
    cout << "(" << number1 << ")" << " - " << "(" << number2
    << ") = " << (number1 - number2) << endl;
    cout << "(" << number1 << ")" << " * " << "(" << number2
    << ") = " << (number1 * number2) << endl;
    cout << "(" << number1 << ")" << " / " << "(" << number2
    << ") = " << (number1 / number2) << endl;
    cout << "|" << number1 << "|" << " = " << number1.abs() << endl;
    cout << "|" << number2 << "|" << " = " << number2.abs() << endl;
    
    number1[0] = 3.4;
    cout << number1++ << endl;
    cout << ++number2 << endl;
    cout << (3 + number2) << endl;
    cout << (number2 += number1) << endl;
    cout << (number2 *= number1) << endl;
    
    number1 = number2;
    cout << number1 << endl;
    cout << number2 << endl;
    
    cout << (number1 < number2) << endl;
    cout << (number1 <= number2) << endl;
    cout << (number1 == number2) << endl;
    cout << (number1 != number2) << endl;
    cout << (number1 > number2) << endl;
    cout << (number1 >= number2) << endl;
    
    return 0;
}
