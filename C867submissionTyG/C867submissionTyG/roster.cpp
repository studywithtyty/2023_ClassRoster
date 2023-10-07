//
//  roster.cpp
//  C867submissionTyG
//
//  Created by Ty Alexia on 7/27/23.


#include <iostream>
#include  <string>
#include "roster.h"
#include <stdio.h>

#include <array>
using namespace std;

void Roster :: parse(string sdata){ //finding each piece of roster data
    
    //find student id value
    size_t rhs = sdata.find(",");
    string studentID = sdata.substr(0,rhs);
    
    //find student first name value
    size_t lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    string firstName = sdata.substr(lhs, rhs - lhs);
    
    //find student last name value
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    string lastName = sdata.substr(lhs, rhs - lhs);
    
    //find student email value
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    string emailAddress = sdata.substr(lhs, rhs - lhs);
    
    //find student age value
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    int studentAge = stoi(sdata.substr(lhs, rhs - lhs)); //stol, stod
    
    //find course 1
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    int c1 = stoi(sdata.substr(lhs, rhs - lhs));
    
    //find course 2
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    int c2 = stoi(sdata.substr(lhs, rhs - lhs));
    
    //find course 3
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    int c3 = stoi(sdata.substr(lhs, rhs - lhs));
    
    //find degree program
    lhs = rhs + 1;
    rhs = sdata.find(",", lhs);
    string strdegreeProgram = sdata.substr(lhs, rhs - lhs);
    
    //Default degree program is NETWORK.
    DegreeProgram degreeProgram = DegreeProgram::NETWORK;
    
    //If the string from parsed data = "SECURITY" then the degree program will update to SECURITY.
     if (strdegreeProgram == "SECURITY") {degreeProgram = DegreeProgram::SECURITY;}
    
    //If the string from parsed data = "SOFTWARE" then the degree program will update to SOFTWARE.
     else if (strdegreeProgram == "SOFTWARE") {degreeProgram = DegreeProgram::SOFTWARE;}
     
    add(studentID, firstName, lastName, emailAddress, studentAge, c1, c2, c3, degreeProgram);}



//Add constructor with defined array for days in course.
void Roster :: add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourseI, int DaysInCourseII, int DaysInCourseIII, DegreeProgram degreeprogram)
    {int allDaysArray[3] = {DaysInCourseI, DaysInCourseII, DaysInCourseIII};
    
    //Roster array that holds student strings, up to index fV (only 5).
    classRosterArray[++finalValue] = new Student(StudentID, FirstName, LastName, EmailAddress, Age, allDaysArray, degreeprogram);}



//Print all parsed data.
void Roster :: printAllS(){
    Student :: printTitle();
    //For an incremented roster int <= fV, add to class array to print.
    for (int i = 0; i <= Roster :: finalValue; i++){Roster :: classRosterArray[i]-> print();}}
        


//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster :: printSInvalidEmails(){
    //For an incremented int that is <= fV will go through loop.
    for (int i = 0; i <= finalValue; i++){
        
        //eMail is value assigned getter.
        string eMail = classRosterArray[i]->geteMail();
        
//Checking each character in email string for ' ', to set as invaild.
for (int ty = 0; ty < classRosterArray[i]->geteMail().length(); ty++){
if (eMail[ty] == ' '){cout << '"' << eMail << '"' << " - is invalid. " << endl;}}
        
    //If there isn't an "@" found throughout string email is invalid.
    if (eMail.find("@") == string::npos){
    cout << '"' << classRosterArray[i]->geteMail() << '"' << " - is invalid." << endl;}
        
           //If there isn't a "." throughout string then email is invalid.
           else if (eMail.find(".") == string::npos){
               cout << '"' << classRosterArray[i]->geteMail() << '"' << " - is invalid." << endl;}}}



//print average days in course
void Roster :: printSAvgTimeInCourse(string studentID){
   //For an incremented int <= fV, retrieve ID. Print their avg (day1 + day2 + day3)/3.
    for (int i = 0; i <= Roster :: finalValue; i++){
        if (studentID == classRosterArray[i]->getID()){
            cout << "Student ID: " << classRosterArray[i]->getID() << ",";
            cout << " Average days in course is: " << (classRosterArray[i]->getcDays()[0] + classRosterArray[i]->getcDays()[1] + classRosterArray[i]->getcDays()[2])/3 << endl;}}}



//print by degree program
void Roster :: printBySDegreeProgram(DegreeProgram degreeprogram){
    
     Student :: printTitle();
     //For an incremented int <= fV, retrieve degree program.
     for (int i = 0; i <= Roster :: finalValue; i++){
         //Print when called.
         if (Roster :: classRosterArray[i]->getdegreeProgram() == degreeprogram)
        {classRosterArray[i]->print(); }} cout << endl;}



//Revokes visibility for specific student ID called.
void Roster :: removeS(string studentID){
    
    bool complete = false;
    //An incremented int <= fV, must be equal to the called ID to become true.
    for (int i = 0; i <= Roster :: finalValue; i++){
        if (classRosterArray[i]->getID() == studentID){complete = true;
            //If int is < nSM decreased by one, set int to save.
            
            Student* save = classRosterArray[i];
            if (i < finalValue){classRosterArray[i] = classRosterArray[finalValue];}
            delete save;
            Roster :: finalValue --;}}
    
    //if false print below
    if (complete)
   {cout << "Attempt to remove " << studentID <<  " was successful" << endl; this -> printAllS();
       } else cout << "The student with the ID: " << studentID << " was not found." << endl;} //end

    


//nulptr delete (destructor) Release all allocated memory
Roster :: ~Roster(){
    for (int i = 0; i <= finalValue; i++)
    {delete classRosterArray[i]; classRosterArray[i] = nullptr;}
    cout << "Done." << endl;}

