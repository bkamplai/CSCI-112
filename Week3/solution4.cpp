//
//  solution4.cpp
//  Week3
//
//  Created by Brandon Kamplain on 2/11/22.
//

#include <iostream>
#include <algorithm>
using namespace std;

char* strstr(const char*, const char*);

int main()
{
    char s1[] = "The cat in the hat", s2[] = "cat";
    
    strstr(s1, s2);
    
    return 0;
}

char* strstr(const char *s1, const char *s2)
{
    char * p = (char*) find(s1, s1 + 17, s2);
    
    if (p != s1 + 17)
      cout << "The string " << *p << " is found at position " << (p - s1) << endl;
    else
      cout << "The string " << s2 << " is not found" << endl;
    
    return 0;
}
