//
//  stackADT.h
//  PrimeStackFun
//
//  Created by Brandon Kamplain on 4/25/22.
//

#ifndef stackADT_h
#define stackADT_h

template<class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0; //Initialize stack to an empty data state
    virtual bool isEmptyStack() const = 0; //Function to determine if stack is empty
    virtual bool isFullStack() const = 0; //Function to determine if stack is full //Precondition: stack must exist
    virtual void push(const Type& newItem) = 0; //Add new item to stack //Precondition: stack exist and is not full
    virtual void pop() = 0; //Function to remove item at top of stack //Precondition: stack exist and has something in it //Postcondition: stack has changed top item has been removed
};

#endif /* stackADT_h */
