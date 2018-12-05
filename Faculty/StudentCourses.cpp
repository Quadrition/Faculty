//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : Milan Pavlov
// Version     : 1.1
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "StudentCourses.h"
#include <iostream>

using std::cout;
using std::endl;

/*
	Initializes empty Student object with its empty courses
*/
StudentCourses::StudentCourses()
{
}

/*
	Destructs Student object
*/
StudentCourses::~StudentCourses()
{
}

/*
	Initializes Student object with its courses
*/
StudentCourses::StudentCourses(const Student &student, const Courses &courses) : student(student), courses(courses)
{
}

/*
	Returns a student
*/
Student StudentCourses::get_student() const
{
	return this->student;
}

/*
	Returns a course that student have
*/
Courses StudentCourses::get_courses() const
{
	return this->courses;
}

/*
	Returns a final score of course that student takes
*/
double StudentCourses::get_final_score() const
{
	return this->courses.get_final_score();
}

/*
	Displays a student and a course that student takes on standard output
*/
void StudentCourses::display() const
{
	cout << "==StudentCourses==" << endl;
	this->student.display();
	this->courses.display();
}

istream &operator>>(istream &in, StudentCourses &sc)
{
	in >> sc.student;
	in >> sc.courses;

	sc.courses.calc_final_score();
	sc.courses.calc_letter_grade();

	return in;
}

ostream &operator<<(ostream &out, StudentCourses &sc)
{
	out << sc.get_student().get_id() << " " << sc.get_student().get_first_name() << " "  << sc.get_student().get_last_name() << " " << sc.get_courses().get_final_score() << " " << sc.get_courses().get_letter_grade() << endl;

	return out;
}
