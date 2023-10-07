//
//  class.h
//  C867submissionTyG


#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

#include <string>

using namespace std;

//
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

#include <string>

using namespace std;

class Student {
    
public:
    //intializing variable to hold # of courses
    const static int numArrayDays = 3;

private:
    //creating variables for constructor
    string studentID;
    string sFirstName;
    string sLastName;
    string sEmailAddress;
    int studentAge;
    //array of # of days to complete each course (3 courses total)
    int courseDays [numArrayDays];
    DegreeProgram degreeProgram;
    
public:
    
    Student(); //empty constructor
    //full constructor
    Student(string studentID, string firstNameS, string lastNameS, string emailAddressS, int studentAgeS, int courseDays[], DegreeProgram degreeProgram);
    
    //destructor
    ~Student();
    
    //getters
    string getID();
    string getfName();
    string getlName();
    string geteMail();
    int getsAge();
    int* getcDays();
    DegreeProgram getdegreeProgram();
    
    //setters
    void setID(string ID);
    void setfName(string fName);
    void setlNames(string lName);
    void seteMail(string eMail);
    void setsAge(int sAge);
    void setcDays(int courseDays[]); //days will be added into courseDays array
    void setdegreeProgram (DegreeProgram degreeProgram);
    
    static void printTitle(); //creating extra space
    void print(); //call to print
};
