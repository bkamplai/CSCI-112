//
//  palidrome.cpp
//  week9
//
//  Created by Brandon Kamplain on 3/30/22.
//

#include <iostream>
using namespace std;

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

struct node
{
    char base;
    node* next;
};

int main()
{
    typedef node* nodePtr;
    LinkedList<nodePtr> ListOfNodePtr;
    
    
    nodePtr nPtr;
    
    nPtr = new node;
    
    
    cout << "Enter text: ";
    
    cin >> input;
    
    for (int i = 0; i<sizeof(input); i++)
        cout << input;
    
    cout << endl << nPtr->base << nPtr->base << endl;
     
    
    if(!ListOfNodePtr.IsEmpty())
        nPtr = ListOfNodePtr.Remove();
    
    delete nPtr;
     
    return 0;
}

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
