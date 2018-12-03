//============================================================================
// File Name   : Student.h
// Authors     : Milan Pavlov
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using std::string;
using std::istream;

// Represents a student with identification, first and last name
class Student
{
private:
	string first_name;
	string last_name;
	string id;

public:
	// Initializes an empty Student
	Student();

	// Destructs the student
	~Student();

	// Student constructor with parameters
	Student(const string &first_name, const string &last_name, const string &id);

	// Returns the first name of student
	string get_first_name() const;

	// Returns the last name of student
	string get_last_name() const;

	// Returns the student identification
	string get_id() const;

	// Prints the student on standard output
	void display() const;

	friend istream &operator>> (istream &in, Student &student);
};

#endif /*STUDENT_H_*/
