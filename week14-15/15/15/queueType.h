//
//  queueType.h
//  15
//
//  Created by Brandon Kamplain on 5/6/22.
//

#ifndef queueType_h
#define queueType_h
#include <iostream>
#include <cassert>
#include "queueADT.h"
using namespace std;

template<class Type>
class queueType: public queueADT<Type>
{
public:
    const queueType<Type>& operator= (const queueType<Type>&);
    void initializeQueue();
    bool isEmpty() const;
    bool isFull() const;
    void push(const Type& newItem);
    Type front() const;
    void pop();
    queueType(int queueSize = 100);
    queueType(const queueType<Type>& otherQueue);
    ~queueType();
private:
    int maxQueueSize;
    int queueFront;
    int queueBack;
    Type *list;
    void copyQueue(const queueType<Type>& otherQueue);
};

template<class Type>
void queueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueBack = 0;
}

template<class Type>
bool queueType<Type>::isEmpty() const
{
    return(queueBack == 0);
}

template<class Type>
bool queueType<Type>::isFull() const
{
    return (queueBack == maxQueueSize);
}

template<class Type>
void queueType<Type>::push(const Type &newItem)
{
    if(!isFull())
    {
        list[queueBack] = newItem;
        queueBack++;
    }
    else
        cout << "Can't add to a full queue.\n";
}

template<class Type>
Type queueType<Type>::front() const
{
    assert(queueBack != 0);
    return list[queueFront];
}

template<class Type>
void queueType<Type>::pop()
{
    if(!isEmpty())
        queueFront++;
    else
        cout << "Can't remove from an empty queue.\n";
}

template<class Type>
queueType<Type>::queueType(int queueSize)
{
    if(queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must be positive.\n Creating an array of size 100.\n";
        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;
    
    queueFront = 0;
    queueBack = 0;
    list = new Type[maxQueueSize];
}

template<class Type>
queueType<Type>::~queueType()
{
    delete [] list;
}

template<class Type>
void queueType<Type>::copyQueue(const queueType<Type> &otherQueue)
{
    delete [] list;
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    
    list = new Type[maxQueueSize];
    
    for(int i = 0; i < queueBack; i++)
        list[i] = otherQueue.list[i];
}

template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    list = nullptr;
    copyQueue(otherQueue);
}

template<class Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type> & otherQueue)
{
    if(this != &otherQueue)
        copyQueue(otherQueue);
    return *this;
}

#endif /* queueType_h */
