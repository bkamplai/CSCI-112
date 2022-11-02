//
//  linkedStack.h
//  PrimeStackFun
//
//  Created by Brandon Kamplain on 4/25/22.
//

#ifndef linkedStack_h
#define linkedStack_h
#include "stackADT.h"
#include <iostream>
#include <cassert>
using namespace std;

//define node
template<class Type>
struct nodeType
{
    Type info;
    nodeType *link;
};

template<class Type>
class linkedStackType: public stackADT<Type>
{
public:
    const linkedStackType<Type>& operator =(const linkedStackType<Type>&);  //overloaded =
    bool isEmptyStack() const;  //precondition: stack exists, return tree if empty
    bool isFullStack() const;   //precondition: stack exist, return true if full
    void initializeStack(); //initialize stack to empty state
    void push(const Type& newItem); //precondition: statck exiss and is not full. Postcondition: stack contents changed new item up top occupancy++
    Type top() const;   //returns the top element in the stack, stack must exist and not empty. If empty program terminates
    void pop(); //Function to remove item at top of stack //Precondition: stack exist and has something in it //Postcondition: stack has changed top item has been removed
    linkedStackType();  //default constructor create empty stack. Postcondition: stackTop = nullptr
    linkedStackType(const linkedStackType<Type>& otherStack);
    ~linkedStackType();
private:
    nodeType<Type> *stackTop;   //pointer to the stack
    void copyStack(const linkedStackType<Type>& otherStack);    //make copy of otherstack
};

//Implementation
template<class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

template<class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template<class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template<class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> * temp;
    while(stackTop != nullptr)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}

template<class Type>
void linkedStackType<Type>::push(const Type &newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = stackTop;
    stackTop = newNode;
}

template<class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr);
    return stackTop->info;
}

template<class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;
    if(stackTop != nullptr)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    else
        cout << "Cannot remove from an empty stack you know!\n";
}

template<class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;
    if(stackTop != nullptr)
        initializeStack();
    if(otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;
        last = stackTop;
        current = current->link;
        while(current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template<class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

#endif /* linkedStack_h */
