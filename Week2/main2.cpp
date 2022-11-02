//
//  main2.cpp
//  Week2
//
//  Created by Brandon Kamplain on 2/4/22.
//

#include <iostream>

using namespace std;

struct employee
{
    int employee_no;
    char employee_name[128];
};
const int MAX = 5;

bool addemployee(employee*& record);
// creates an employee structure dynamically

int addemployees(employee*& record);

int main()
{
    employee* employees[MAX] = {NULL};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (addemployee(employees[i]))
            break;
    }

    // add function to output employees
    
    // add function to free all employees from the array
    
    return 0;
}

bool addemployee(employee*& record)
{
    struct newEmployee
    {
        int employee_num;
        char employee_name;
    };
    
    for (int i=0; i<5; i++)
    {
        cout << "Please enter employee's name: ";
        cin >> newEmployee[i];
        cout << "Please enter employee's number: ";
        cin >>
    }
    
    return 0;
}
