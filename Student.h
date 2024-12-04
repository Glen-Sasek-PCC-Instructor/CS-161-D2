//The student struct
#ifndef Student_H_
#define Student_H_

const int MAX_CHAR = 20;
struct Student {
	char first[MAX_CHAR+1];
	char last[MAX_CHAR+1];
	double gpa;
};

//Function Prototypes
Student initStudent(char *first, char *last, double gpa);
void getLastName(char *studenLastName, Student student);
double getGPA(Student student);
void printStd(Student student);

#endif