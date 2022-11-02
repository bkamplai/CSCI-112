//
//  LinkedList.h
//  week9
//
//  Created by Brandon Kamplain on 3/30/22.
//

#ifndef LinkedList_h
#define LinkedList_h

template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void Initialise();
    bool IsEmpty(); //true if list is empty
    void Add(const T&); //passes pointer to data
    T Remove(); //returns a data value
private:
    struct Node;
    typedef Node* NodePtr;
    struct Node
    {
        T data;
        NodePtr next;
    };
    NodePtr Head;
};

#endif /* LinkedList_h */
