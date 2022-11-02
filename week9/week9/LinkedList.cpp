//
//  LinkedList.cpp
//  week9
//
//  Created by Brandon Kamplain on 3/30/22.
//

#include <stdio.h>
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() //constructor
{
    Head = 0;
}

template<class T>
LinkedList<T>::~LinkedList() //destructor
{
    NodePtr tmp;
    while (Head != 0)
    {
        tmp = Head; //copy the head pointer
        Head = Head->next; //change head ptr
        delete tmp; //delete old head's memory
    }
}

template<class T>
void LinkedList<T>::Initialise()
{
    Head = 0;
}

template<class T>
bool LinkedList<T>::IsEmpty()
{
    return (Head == 0);
}

template<class T>
void LinkedList<T>::Add(const T& data)
{
    NodePtr tmp, curr;
    
    //create a node and store the information
    tmp = new Node;
    tmp->data = data;
    tmp->next = 0;
    
    //add to end of the list if list isn't empty
    if (Head != 0)
    {
        curr = Head;
        while (curr->next) //is this the end?
            curr = curr->next;
        curr->next = tmp;
    }
    else
        Head = tmp;
}

template<class T>
T LinkedList<T>::Remove()
{
    NodePtr tmp;
    T data;
    
    data = Head->data; //assume something there
    tmp = Head; //make a copy of head pointer
    Head = Head->next; //change the head
    delete tmp; //delete the old head's memory
    return data;
}
