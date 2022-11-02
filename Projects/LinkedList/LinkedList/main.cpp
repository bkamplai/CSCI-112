//
//  main.cpp
//  LinkedList
//
//  Created by Brandon Kamplain on 3/29/22.
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

struct Customer
{
    char name[20];
    int number;
};

struct Video
{
    char Title[41]; //40 character string
    long BarCode;
    short RunTime; //in minutes
    char Category[11];
    short NumCopies;
};

int main()
{
    typedef Video* VideoPtr;
    LinkedList<VideoPtr> ListofVideoPtr;
    
    VideoPtr Vptr;
    
    //to add a video
    Vptr = new Video;
    
    //Vptr->Title = "Bond!ng";
    Vptr->BarCode = 12345;
    Vptr->RunTime = 45;
    //Vptr->Category = "Raunchy";
    Vptr->NumCopies = 1;
    
    ListofVideoPtr.Add(Vptr);
    
    //to add a video
    Vptr = new Video;
    
    Vptr->BarCode = 54321;
    Vptr->RunTime = 15;
    Vptr->NumCopies = 9;
    
    ListofVideoPtr.Add(Vptr);
    
    if (!ListofVideoPtr.IsEmpty())
        Vptr = ListofVideoPtr.Remove();
    //do what we want with *Vptr
    delete Vptr; //avoid leakage
    
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
