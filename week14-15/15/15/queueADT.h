//
//  queueADT.h
//  15
//
//  Created by Brandon Kamplain on 5/6/22.
//

#ifndef queueADT_h
#define queueADT_h
template<class Type>
class queueADT
{
public:
    virtual void initializeQueue() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(const Type& newItem) = 0;
    virtual Type front() const = 0;
    virtual void pop() = 0;
};
#endif /* queueADT_h */
