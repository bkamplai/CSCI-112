//
//  main.cpp
//  15
//
//  Created by Brandon Kamplain on 5/4/22.
//

#include <iostream>
#include <string>
#include "stackADT.h"
#include "stackType.h"
#include "queueADT.h"
#include "queueType.h"
using namespace std;

void toUpper(char ch);

int main(int argc, const char * argv[]) {
    
    string userInput;
    queueType<char> queue;
    stackType<char> stack;
    bool isPalindrome = true;
    
    cout << "Enter a string of characters: ";
    getline(cin, userInput);
    
    for(auto ch : userInput)
    {
        ch = toupper(ch);
        queue.push(ch);
        stack.push(ch);
    }
    
    while (!queue.isEmpty() && !stack.isEmpty())
    {
        if(queue.front() != stack.top())
        {
            isPalindrome = false;
            break;
        }
        queue.pop();
        stack.pop();
    }
    
    if(isPalindrome)
        cout << userInput << " is a palindrome!\n";
    else
        cout << userInput << " is not a palindrome.\n";
    
    return 0;
}
