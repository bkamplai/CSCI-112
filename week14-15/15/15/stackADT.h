//
//  stackADT.h
//  15
//
//  Created by Brandon Kamplain on 5/4/22.
//

#ifndef stackADT_h
#define stackADT_h
template<class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(const Type& newItem) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};

#endif /* stackADT_h */
