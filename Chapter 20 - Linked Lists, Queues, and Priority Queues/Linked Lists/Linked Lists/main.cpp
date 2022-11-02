//
//  main.cpp
//  Linked Lists
//
//  Created by Brandon Kamplain on 3/24/22.
//

#include <iostream>
#include "PriorityQueue.h"
#include <string>
using namespace std;

class Patient
{
public:
  Patient(const string& name, int priority)
  {
    this->name = name;
    this->priority = priority;
  }

  bool operator<(const Patient& secondPatient)
  {
    return (this->priority < secondPatient.priority);
  }

  bool operator>(const Patient& secondPatient)
  {
    return (this->priority > secondPatient.priority);
  }

  string getName() const
  {
    return name;
  }

  int getPriority() const
  {
    return priority;
  }

private:
  string name;
  int priority;
};

int main()
{
  // Queue of patients
  PriorityQueue<Patient> patientQueue;
  patientQueue.enqueue(Patient("John", 2));
  patientQueue.enqueue(Patient("Jim", 1));
  patientQueue.enqueue(Patient("Tim", 5));
  patientQueue.enqueue(Patient("Cindy", 7));

  while (patientQueue.getSize() > 0)
  {
    Patient element = patientQueue.dequeue(); // Get a patient from the queue
    cout << element.getName() << " (priority: " <<
      element.getPriority() << ") ";
  }

  return 0;
}
