//
//  roster.h
//  C867submissionTyG


#pragma once
#include "student.h"

using namespace std;

class Roster{
private:
    int placeHolder = 0;
    int n = 3;
    
public:
    //final indexed value int
    int finalValue = -1;
    //constant maximum # of students in an array
    const static int numStudentsMax = 5;
    //sets class array # to 5
    Student* classRosterArray[numStudentsMax];
    
    
public:
    //seperate fields from comma
    void parse(string sdata);
    //roster student data WGU
    void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourseI, int DaysInCourseII, int DaysInCourseIII, DegreeProgram degreeProgram);
    void removeS(string studentID);
    void printAllS();
    void printSAvgTimeInCourse(string studentID);
    void printSInvalidEmails();
    void printBySDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram degreeProgram;
    
    //destructor
    ~Roster ();
};
