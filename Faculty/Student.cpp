//============================================================================
// File Name   : Student.cpp
// Authors     : Milan Pavlov
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "Student.h"
#include <iostream>
#include <sstream>
#include "Menu.h"

using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
using std::string;
using std::istream;

/*
	Student empty constructor
*/
Student::Student()
{
}

/*
	Student destructor
*/
Student::~Student()
{
}

/*
	Student constructor with parameters
*/
Student::Student(const string &first_name, const string &last_name, const string &id) : first_name(first_name), last_name(last_name), id(id)
{
}

/*
	Returns the first name of student
*/
string Student::get_first_name() const
{
	return this->first_name;
}

/*
	Returns the last name of student
*/
string Student::get_last_name() const
{
	return this->last_name;
}

/*
	Returns the student identification
*/
string Student::get_id() const
{
	return this->id;
}

/*
	Prints the student on standard output
*/
void Student::display() const
{
	cout << "=Student=" << endl;
	cout << "Identification: " << this->id << endl;
	cout << "First name: " << this->first_name << endl;
	cout << "Last name: " << this->last_name << endl;
}

istream &operator>>(istream &in, Student &student)
{
	string line;
	getline(in, line);
	stringstream stream(line);

	stream >> student.first_name >> student.last_name >> student.id;

	if (stream.fail())
		throw Menu::InvalidData();

	return in;
}

