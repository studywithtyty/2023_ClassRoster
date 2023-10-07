//
//  class.cpp
//  C867submissionTyG


#include <iostream>
#include <string>

#include <stdio.h>
#include "student.h"
using namespace std;

//basic constructor (used if output is not declared)
Student :: Student (){
    
    this -> studentID = "ZZZ";
    this -> sFirstName = "YYY";
    this -> sLastName = "XXX";
    this -> sEmailAddress = "WWW";
    this -> studentAge = 0;
    //will always output 0
    for (int i = 0; i < numArrayDays; i++)this -> courseDays[i] = 0;
    this -> degreeProgram = DegreeProgram :: SOFTWARE;}

//completed constructor
Student :: Student (string studentID, string firstName, string lastName, string emailAddress, int studentAge, int courseDays[], DegreeProgram degreeProgram){
    
    //returning assigned values
    this -> studentID = studentID;
    this -> sFirstName = firstName;
    this -> sLastName = lastName;
    this -> sEmailAddress = emailAddress;
    this -> studentAge = studentAge;
    //for an indexed value less than 3, set = to courseDays & increase value by 1
    for (int i = 0; i < numArrayDays; i++) this -> courseDays[i] = courseDays[i];
    this -> degreeProgram = degreeProgram;}

//Destructor with no action
Student :: ~Student(){}

//getter used to grab information
string Student :: getID() {return this -> studentID;}
string Student :: getfName() {return this -> sFirstName;}
string Student :: getlName() {return this -> sLastName;}
string Student ::geteMail() {return this -> sEmailAddress;}
int Student :: getsAge() {return this -> studentAge;}
//pointer to an int variable is called (int*)
int* Student :: getcDays() {return this -> courseDays;}
DegreeProgram Student :: getdegreeProgram() {return this -> degreeProgram;} //end

//setter used to intialize variable
void Student :: setID(string ID) {this -> studentID = ID;}
void Student :: setfName(string fName) {this -> sFirstName = fName;}
void Student :: setlNames(string lName) {this -> sLastName = lName;}
void Student :: seteMail(string eMail) {this -> sEmailAddress = eMail;}
void Student :: setsAge(int sAge) {this -> studentAge = sAge;}
void Student :: setcDays(int []){
    for (int i = 0; i < numArrayDays; i++) this -> courseDays[i] = courseDays[i];}
void Student :: setdegreeProgram(DegreeProgram degreeProgam) {this -> degreeProgram = degreeProgam;} //end


//print title for output
void Student :: printTitle(){
    cout << endl;} //end

//print method format
void Student :: print(){
    //tabbing each piece of parsed info
    cout << this -> getID() << '\t';
    cout << this -> getfName() << '\t';
    cout << this -> getlName() << '\t';
    cout << this -> geteMail() << '\t';
    cout << this -> getsAge() << '\t';
    cout << "{"; //adding opening & closing brakets to # of course days
    cout << this -> getcDays()[0] << ',';
    cout << " " << this -> getcDays()[1] << ',';
    cout << " " << this -> getcDays()[2];
    cout << "} ";
    cout << degreeProgramStrings[this ->getdegreeProgram()] << '\n';
}
