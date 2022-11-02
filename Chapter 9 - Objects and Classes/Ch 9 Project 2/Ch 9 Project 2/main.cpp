//
//  main.cpp
//  Ch 9 Project 2
//
//  Created by Brandon Kamplain on 2/6/22.
//
/*
Instructions:
(The "EvenNumber" class) Define the "EvenNumber" class for representing an even number. The class contians:
- A data field "value" of the int type that represents the integer value stored in the object.
- A no-arg constructor that creates an "EvenNumber" object for the value 0.
- A constructor that constructs an "EvenNumber" object with the specified value.
- A function named "getValue()" to return an int value for this object.
- A function named "getNext()" to return an "EvenNumber" object that represents the next even number after the current even number in this object.
- A fucntion named "getPrevious()" to return an "EvenNumber" object that represents the previous even number before the current even number in this object.
Draw the UML diagram for the class. Implement the class. Write a test program that creats an "EvenNumber" object for value 16 and invokes the "getNext()" and "getPrevious()" functions to obtain and displays these numbers.
*/

#include <iostream>

using namespace std;

class EvenNumber
{
public:
    int value;
    
    EvenNumber()
    {
        value = 0;
    }
    
    EvenNumber(int newValue)
    {
        value = newValue;
    }
    
    int getValue()
    {
        return value;
    }
    
    int getNext()
    {
        if (value%2 == 0)
            return value = value + 2;
        else
            return value++;
    }
    
    int getPrevious()
    {
        if (value%2 == 0)
            return value = value - 4;
        else
            return value = value - 2;
    }
};

int main()
{
    EvenNumber evenNumber2(16);
    
    cout << "The next even number in succession of " << evenNumber2.getValue() << " is " << evenNumber2.getNext() << " and the previous even number is " << evenNumber2.getPrevious() << endl;
    
    return 0;
}
