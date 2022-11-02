#include <iostream>
#include "LiveExample_14-11_CourseWithAssignmentOperatorOverloaded.h"
using namespace std;

void printStudent(const string names[], int size)
{
  for (int i = 0; i < size; i++) 
    cout << names[i] << (i < size - 1 ? ", " : " ");
}

int main()
{
  Course course1("C++", 10);
  Course course2("Java", 10);

  // Assign course1 to course2
  course2 = course1; 
  course1.addStudent("Peter Pan"); // Add a student to course1
  course2.addStudent("Lisa Ma"); // Add a student to course2

  cout << "students in course1: ";
  printStudent(course1.getStudents(), course1.getNumberOfStudents());
  cout << endl;

  cout << "students in course2: ";
  printStudent(course2.getStudents(), course2.getNumberOfStudents());
  cout << endl;

  return 0;
} 