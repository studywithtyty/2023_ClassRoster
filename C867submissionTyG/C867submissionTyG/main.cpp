//
//  main.cpp
//  C867submissionTyG
//

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
    
    //modify student table to contain info
    const string studentDataWGU[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ty,Gilbert,tgil219@wgu.edu,21,23,24,25,SOFTWARE"};
    
    //print student info
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011018242" << endl;
    cout << "Ty Gilbert" << endl;  cout << endl;
    
    //Intializing int for maximum amount of students & creating classRoster.
    const int numStudentsMax = 5;
    Roster classRosterWGU;
    
    //For an indexed value less than 5, add a student string to the classRoster & increase value by 1.
    for (int i = 0; i < numStudentsMax; i++) classRosterWGU.parse(studentDataWGU[i]);
    cout << "Displaying all students: " << endl;
    classRosterWGU.printAllS(); cout << endl;
    
    cout << "Displaying invalid emails : " << endl;
    classRosterWGU.printSInvalidEmails(); cout << endl; //printing all invalid emails
    
    cout << "Showing average days to complete each course: " << endl;
    for (int i = 1; i < 6; i++){
        classRosterWGU.printSAvgTimeInCourse("A" + to_string(i));} cout << endl; //printing avg days to complete course
  
    cout << "Showing students by degree program: " << endl;
    classRosterWGU.printBySDegreeProgram(SOFTWARE); cout << endl; //print all students in the degree program SOFTWARE
    
    cout << "Removing A3:" << endl;
    classRosterWGU.removeS("A3"); cout << endl; //remove student with ID: A3
    
    cout << "Removing A3 Again" << endl;
    classRosterWGU.removeS("A3"); cout << endl; //remove student with ID: A3
    
    //system("pause");
    //return 0;
}
