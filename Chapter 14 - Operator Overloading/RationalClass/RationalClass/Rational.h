//
//  Rational.h
//  RationalClass
//
//  Created by Brandon Kamplain on 2/22/22.
//

#ifndef Rational_h
#define Rational_h
#include <string>

using namespace std;

class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;
    Rational add(const Rational& secondRational) const;
    Rational subtract(const Rational& secondRational) const;
    Rational multiply(const Rational& secondRational) const;
    Rational divide(const Rational& secondRational) const;
    int compareTo(const Rational& secondRational) const;
    bool equals(const Rational& secondRational) const;
    int intValue() const;
    double doubleValue() const;
    string toString() const;
    
    bool operator< (const Rational& secondRational) const;
    //Rational operator+(const Rational& secondRational) const;
    //Rational operator+(const Rational r1, const Rational& r2);
    
    operator double();
    Rational(int numerator);

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

#endif /* Rational_h */
