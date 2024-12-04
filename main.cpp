// The client file or the driver file
// This file has the main() function
// Add header comments here.
#include <iostream>
#include <cstring>
#include <fstream>

#include "Student.h"
#include "Course.h"
// #include "cmake-build-debug/Student.h"

using namespace std;

int main()
{
  Course course = initCourse();
  ifstream inFile;
  cout << "Welcome to my Course Roster Program\n"
       << endl;
  inFile.open("students.txt");
  if (!inFile)
  {
    cout << "File did not open! Program Exiting!!" << endl;
    return 0;
  }

  readStudent(inFile, course);
  cout << "Here is the course roster: " << endl;
  printRoster(course);

  // call the appropriate functions based on the grade level you are choosing.
  // calls dropStudent to drop a student from the roster.
  char lastName[MAX_CHAR] = "Robison";
  dropStudent(lastName, course);

  Student student = initStudent("New", "Student", 4.0);
  addStudent(student, course);

  // read a last name into a char array and pass to function.
  // declare variables if needed
  // readStudent(inFile, course);

  /*Add code here to call function*/

  // calls printRoster to print the roster after the student drop.
  // Uncomment the next 2 lines once you have dropped a student
  cout << "\nHere is the course roster: " << endl;
  printRoster(course);

  // calls findStudentHighestGPA to get Student with highest GPA
  // declare variables if needed

  /*Add code here to call function*/

  // calls printStd to print the student with the highest GPA

  /*Add code here to call function*/

  cout << "Thank you for using my Student Roster program!!" << endl;
  return 0;
}