//
//  main.cpp
//  week8
//
//  Created by Brandon Kamplain on 3/16/22.
//

#include <iostream>
using namespace std;

struct student
{
    char name[128];
    int age;
    char gender[1];
    int courseno;
};

bool checkMemAlloc(student);

int main()
{
    
    int num;
    cout << "Enter number of students: ";
    cin >> num;
    
    student *studentInfo;
    
    studentInfo = new (nothrow) student[num];
    
    for (int i = 0; i < num; i++)
    {
        cout << "Enter name: ";
        cin >> studentInfo[i].name;
        cout << "Enter age: ";
        cin >> studentInfo[i].age;
        cout << "Enter gender: ";
        cin >> studentInfo[i].gender;
        cout << "Enter course number: ";
        cin >> studentInfo[i].courseno;
    }
    
    for (int i = 0; i < num; i++)
        {
            cout << "Name: " << studentInfo[i].name << "\tAge: " << studentInfo[i].age << "\tGender: " << studentInfo[i].gender << "\tCourse Number: " << studentInfo[i].courseno << endl;
        }
    
    delete[] studentInfo;
    
    return 0;
}

bool checkMemAlloc(student *ptr)
{
    if (!ptr)
        return false;
    else
        return true;
}
