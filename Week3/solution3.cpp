//
//  solution3.cpp
//  Week3
//
//  Created by Brandon Kamplain on 2/9/22.
//

#include <iostream>
using namespace std;

void reverse(char*);

int main()
{
    char data[] = "The cat sat on the red mat";
    
    reverse(data);
    
    cout << endl;
    
    return 0;
}

void reverse(char* src)
{
    char * begin = src;
    while (*src != '\0')
    {
        src++;
    }
    while (src >= begin)
    {
        cout << *src--;
    }
}
