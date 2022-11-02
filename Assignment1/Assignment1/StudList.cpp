// See assignment specs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "StudList.h"
using namespace std;

const char STUDENT_FILE[] = "student.txt";

StudentList::StudentList()
{
    NumOfStudents = 0;
}

StudentList::~StudentList()
{
}

int StudentList::ReadFile()
{// Loads Student array from file
    
    
    return 1;
}

void StudentList::PrintStudentsInSubject(char SubjectCode[])
{// Prints name of all students enrolled in SubjectCode
}

int StudentList::PrintStudentDetails(char StudentID[])
{// Prints name and subjects codes belonging to StudentID
    return 0;
}

void StudentList::PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects)
{// Prints all students doing less than CPLimit
}
