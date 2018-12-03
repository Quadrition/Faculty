//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : Petar Cerovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include "StudentCourses.h"
#include <vector>

using std::vector;
using std::istream;

class GroupOfStudents
{
private:
	vector<StudentCourses> st_vec;

	static const int NUM_BEST = 5;

	void search_for_highest(vector<int> &indices_max) const;

public:
	// Initializes array of Students object
	GroupOfStudents();

	// Destructs array of Students
	~GroupOfStudents();

	// Initializes array of Students with courses
	GroupOfStudents(const vector<StudentCourses> &st_vec);

	// Returns a vector of StudentCourses
	const vector<StudentCourses> get_student_courses() const;

	// Reads a list of StudentCourses from file
	void read_from_file(string file_name);

	// Displays a StudentCourses based on passed identification
	void display(string id) const;

	// Displays StudentCourses with highest total score
	void display_highest() const;

	// Displays GroupOfStudnets sorted by Student last name
	void display_sorted() const;

	// Displays a whole GroupOfStudents
	void display_all() const;

	// Wirtes GroupOfStudents to file
	void write_to_file(string file_name);

	// Checks if GroupOfStudents is empty
	bool is_empty() const;

	friend istream &operator>> (istream &in, GroupOfStudents &gs);
	friend ostream &operator<< (ostream &out, GroupOfStudents &gs);
};

#endif /*GROUPOFSTUDENTS_H_*/
