// See assignment specs

#include <iostream>
#include <cstring>
#include "subject.h"
using namespace std;

Subject::Subject()
{// Default constructor
}

Subject::Subject(int pSemester,char pIDNumber[4],char pName[26],int pCreditPoints)
{// Initialisation constructor
    Semester = pSemester;
    for (int i = 0; i < 4; i++)
        IDNumber[i] = pIDNumber[i];
    for (int j = 0; j < 26; j++)
        Name[j] = pName[j];
    CreditPoints = pCreditPoints;
}

int Subject::GetSemester()
{
   return Semester;
}

char *Subject::GetIDNumber()
{
   return IDNumber;
}

char *Subject::GetName()
{
   return Name;
}
