//============================================================================
// File Name   : StudentCourses.h
// Authors     : Milan Pavlov
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

using std::istream;
using std::ostream;

// Represents a student with its course results and info
class StudentCourses
{
private:
	Student student;
	Courses courses;

public:
	// StudentCourses empty constructor
	StudentCourses();

	// StudentCourses destructor
	~StudentCourses();

	// StudentCourses constructor with parameters
	StudentCourses(const Student &student, const Courses &courses);

	// Returns a stdeunt
	Student get_student() const;

	// Returns a course that student have
	Courses get_courses() const;

	// Returns a final score of course that student takes
	double get_final_score() const;

	// Displays a student and a course that student takes on standard output
	void display() const;

	friend istream &operator>> (istream &in, StudentCourses &sc);
	friend ostream &operator<< (ostream &out, StudentCourses &sc);
};

#endif /*_STUDENTCOURSES_H_*/
