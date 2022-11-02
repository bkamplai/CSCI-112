//
//  newString.cpp
//  newString
//
//  Created by Brandon Kamplain on 2/15/22.
//

#include "newString.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>

ostream& operator<< (ostream& osObject, const newString& str)
{
    osObject << str.strPtr;
    return osObject;
}

istream& operator>> (istream& isObject, newString& str)
{
    char temp[81];
    isObject >> setw(81) >> temp;
    str = temp;
    return isObject;
}

newString::newString(const char *str)
{
    strLength = strlen(str);
    strPtr = new char[strLength+1];
    strcopy(str);
}
newString::newString()
{
    strLength = 0;
    strPtr = new char[1];
    strPtr[0] = '\n';
}

//const newString& newString::operator= (const newString& rightStr)
//{
//    strLength = rightStr.strLength;
//    strPtr = new char[strLength+1];
//    strcopy(rightStr.strPtr);
//}

newString::~newString()
{
    delete [] strPtr;
}

const newString& newString::operator= (const newString& rightStr)
{
    if (this != &rightStr)
    {
        delete [] strPtr;
        strLength = rightStr.strLength;
        strPtr = new char[strLength+1];
        strcopy(rightStr.strPtr);
    }
    return *this;
}

char& newString::operator[](int index)
{
    assert(0 <= index && index < strLength);
    return strPtr[index];
}

const char& newString::operator[](int index)const
{
    assert(0 <= index && index < strLength);
    return strPtr[index];
}

bool newString::operator== (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)==0);
}

bool newString::operator!= (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)!=0);
}
bool newString::operator<= (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)<=0);
}

bool newString::operator< (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)<0);
}

bool newString::operator>= (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)>=0);
}

bool newString::operator> (const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr)>0);
}

char* newString::strcopy(const char *str2)
{
    for(int i=0; i<strLength; i++)
        strPtr[i] = str2[i];
    strPtr[strLength] = '\0';
    return strPtr;
}

char* newString::strcopy(char *str1, const char* str2)
{
    for(int i=0; i<strlen(str1); i++)
        str1[i] = str2[i];
    str1[strlen(str1)] = '\0';
    return str1;
}
