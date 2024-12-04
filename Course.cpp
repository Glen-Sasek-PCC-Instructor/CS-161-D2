// The implementation file for Course.h
// It loads students from a text file.
#include <iostream>
#include <cstring>
#include "Course.h"
#include "Student.h"

using namespace std;

// initializes a course variable and returns it. The array is empty
// and the number of students is set to 0.
Course initCourse()
{
	Course course;
	course.numStudents = 0;
	return course;
}

// reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{
	char first[MAX_CHAR+1] = {};
	char last[MAX_CHAR+1] = {};
	double gpa = 0.0;
	Student student;

	bool success = true;
	do {
		inFile.getline(first, MAX_CHAR, ';');
		if(inFile) {
			inFile.getline(last, MAX_CHAR, ';');
			inFile >> gpa;
			student = initStudent(first, last, gpa);
			addStudent(student, course);
			inFile.get();			
		} else {
			success = false;
		}
	} while(success);
}

// adds a student to the roster, and increment count
// modify this function to add the student sorted by name
// do not use any sorting functions.
// See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course)
{
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	course.numStudents++;
}

// prints a whole Course roster calling student print.
// use a for loop and print all the students
// must call the printStd function in Student.h
void printRoster(Course course)
{

	for (int i = 0; i < course.numStudents; i++)
	{
		printStd(course.roster[i]);
	}
}

// Based on the grade level you are doing: Please read the appropriate level assignment document.
// add code and function comments for the below 2 functions.

void dropStudent(char *lastname, Course &course)
{
	int foundStu = -1;
	for (int i = 0; i < course.numStudents; i++)
	{
		if (strcmp(course.roster[i].last, lastname) == 0)
		{
			foundStu = i;
			break;
		}
	}
	if (foundStu != -1)
	{
		for (int i = foundStu; i < course.numStudents - 1; i++)
		{
			course.roster[i] = course.roster[i + 1];
		}
		course.numStudents--;
	}
}

Student findStudentHighestGPA(Course course)
{
	int highestStudentIndex = 0;
	for (int i = 0; i < course.numStudents - 1; i++)
	{
		if (course.roster[i].gpa > course.roster[highestStudentIndex].gpa)
		{
			highestStudentIndex = i;
		}
	}
	return course.roster[highestStudentIndex];
}
