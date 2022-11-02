//
//  main.cpp
//  Stack Demo
//
//  Created by Brandon Kamplain on 4/22/22.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

template<typename T>
void printStack(T& stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop(); // Remove an element from stack
    }
}

int main()
{
    stack<int> stack1;
    stack<int, vector<int>> stack2;
    stack<char> stack;
    stack<string> infx;
    stack<string> pfx;
    int len = infx.size();-
    
    for (int i = 0; i < 8; i++)
    {
        stack1.push(i);
        stack2.push(i);
    }
    
    cout << "Contents in stack1: ";
    printStack(stack1);
    
    cout << "\nContents in stack2: ";
    printStack(stack2);
    cout << endl;
    
    for (i = 0; i < len; i++)
        if (infx[i] >= 'A' && infx[i] <= 'Z')
            pfx = pfx + infx[i];
    
    return 0;
}
