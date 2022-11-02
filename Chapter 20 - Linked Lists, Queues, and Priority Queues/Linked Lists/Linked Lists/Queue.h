//
//  Queue.h
//  Linked Lists
//
//  Created by Brandon Kamplain on 3/26/22.
//

#ifndef Queue_h
#define Queue_h
#include "LinkedList.h"
#include <stdexcept>
using namespace std;
  
template<typename T>
class Queue
{
public:
  Queue();
  void enqueue(const T& element);
  T dequeue();
  int getSize() const;
  
private:
  LinkedList<T> list;
};
  
template<typename T>
Queue<T>::Queue()
{
}
  
template<typename T>
void Queue<T>::enqueue(const T& element)
{
  list.addLast(element);
}
  
template<typename T>
T Queue<T>::dequeue()
{
  return list.removeFirst();
}
  
template<typename T>
int Queue<T>::getSize() const
{
  return list.getSize();
}

#endif /* Queue_h */
