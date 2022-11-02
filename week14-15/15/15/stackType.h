//
//  stackType.h
//  15
//
//  Created by Brandon Kamplain on 5/4/22.
//

#ifndef stackType_h
#define stackType_h
#include <iostream>
#include <cassert>
#include "stackADT.h"
using namespace std;

template<class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator= (const stackType<Type>&);
    void initializeStack();
    bool isEmpty() const;
    bool isFull() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
    stackType(int stackSize = 100);
    stackType(const stackType<Type>& otherStack);
    ~stackType();
private:
    int maxStackSize;
    int stackTop;
    Type *list;
    void copyStack(const stackType<Type>& otherStack);
};

template<class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template<class Type>
bool stackType<Type>::isEmpty() const
{
    return stackTop == 0;
}

template<class Type>
bool stackType<Type>::isFull() const
{
    return (stackTop == maxStackSize);
}

template<class Type>
void stackType<Type>::push(const Type &newItem)
{
    if(!isFull())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
        cout << "Stack is full. Can't add any more items.\n";
}

template<class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template<class Type>
void stackType<Type>::pop()
{
    if(!isEmpty())
        stackTop--;
    else
        cout << "Can't remove items from an empty stack.\n";
}

template<class Type>
stackType<Type>::stackType(int stackSize)
{
    if(stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must be positive.\n Creating an array of size 100.\n";
        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;
    
    stackTop = 0;
    list = new Type[maxStackSize];
}

template<class Type>
stackType<Type>::~stackType()
{
    delete [] list;
}

template<class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    
    list = new Type[maxStackSize];
    
    for(int i = 0; i < stackTop; i++)
        list[i] = otherStack.list[i];
}

template<class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

template<class Type>
const stackType<Type>& stackType<Type>::operator= (const stackType<Type>& otherStack)
{
    if(this != &otherStack)
        copyStack(otherStack);
    return *this;
}

#endif /* stackType_h */
