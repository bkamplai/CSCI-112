//
//  newString.h
//  newString
//
//  Created by Brandon Kamplain on 2/15/22.
//

#ifndef newString_h
#define newString_h

#include <iostream>
using namespace std;

class newString
{
    friend ostream& operator<< (ostream&, const newString&);
    friend istream& operator>> (istream&, newString&);
    
public:
    newString();
    newString(const char*);
    const newString& operator= (const newString&);
    newString(const newString&);
    ~newString();
    char &operator[] (int);
    const char &operator[] (int) const;
    
    bool operator== (const newString&) const;
    bool operator!= (const newString&) const;
    bool operator<= (const newString&) const;
    bool operator>= (const newString&) const;
    bool operator< (const newString&) const;
    bool operator> (const newString&) const;
private:
    char* strcopy(const char *str2);
    char* strcopy(char *str1, const char* str2);
    
    char *strPtr;
    int strLength;
    
};

#endif /* newString_h */
