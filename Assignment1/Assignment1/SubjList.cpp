// See assignment specs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "subject.h"
#include "SubjList.h"
using namespace std;

const char SUBJECT_FILE[] = "subject.txt";

struct classes
{
    int courseNum;
    char* courseName;
    int numOfCredits;
    int term;
};

typedef classes* classesPtr;

classesPtr DB[MAX_SUBJECT];


SubjectList::SubjectList()
{
   NoOfSubjects=0;
}

SubjectList::~SubjectList()
{

}

int SubjectList::ReadFile()
{// Loads subject array from file
    
    char temp[256];
    int count = 0;
    
    ifstream subjectFile;
    subjectFile.open(SUBJECT_FILE);
    
    //cout << "test\n";

    if (!subjectFile.is_open())
    {
        cerr << "The file could not be opened.\n";
        exit(1);
    }
    
    subjectFile.getline(temp, 256, '\n');
    
    while (!subjectFile.eof())
    {
        //subjectFile.getline(temp, 256, '\n');
       // cout << temp << '\n';
        
        DB[count] = new classes;
        subjectFile >> DB[count]->courseNum;
        
        //subjectFile.getline(temp, 256, '\n');
        
        subjectFile >> temp;
        DB[count]->courseName = new char[strlen(temp)+1];
        strcpy(DB[count]->courseName, temp);
        
        //subjectFile.getline(temp, 256, '\n');
        
        subjectFile >> temp;
        subjectFile >> DB[count]->numOfCredits;
        
        //subjectFile.getline(temp, 256, '\n');
        
        subjectFile >> temp;
        subjectFile >> DB[count]->term;
        
        subjectFile.getline(temp, 256, '\n');
        
        count++;
    }
    
    subjectFile.close();
    
    for (int i = 0; i < count; ++i)
    {
        delete DB[i]->courseName;
        delete DB[i];
    }

   return 1;
}

void SubjectList::PrintSubjectsInSemester(int Semester)
{// Prints all subjects that match Semester
   cout<<"Subjects offered are:\n";
   for(int i=0;i<NoOfSubjects;i++){
      if(Subjects[i]->GetSemester()==Semester){
         cout<<Subjects[i]->GetIDNumber()<<'\t'<<Subjects[i]->GetName()<<endl;
      }
   }
}

int SubjectList::PrintSubjectDetails(char SubjectCode[])
{// Prints subject code & name of subject which matches SubjectCode

   return 0;
}
