//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "GroupOfStudents.h"
#include <iostream>
#include <fstream>
#include "MergeSort.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

void GroupOfStudents::search_for_highest(vector<int>& indices_max) const
{
}

/*
	GroupOfStudents empty constructor
*/
GroupOfStudents::GroupOfStudents()
{
}

/*
	GroupOfStudents destructor
*/
GroupOfStudents::~GroupOfStudents()
{
}

/*
	GroupOfStudents constructor with parameters
*/
GroupOfStudents::GroupOfStudents(const vector<StudentCourses>& st_vec) : st_vec(st_vec)
{
}

/*
	Returns a vector of StudentCourses
*/
const vector<StudentCourses> GroupOfStudents::get_student_courses() const
{
	return this->st_vec;
}

/*
	Reads a list of StudentCourses from file
*/
void GroupOfStudents::read_from_file(string file_name)
{
	string type = "bin";

	if (type == "txt")
	{
		ifstream ifs;
		ifs.open(file_name, ifstream::in);
		ifs >> *this;
	}
	else if (type == "bin")
	{
		ifstream ifs;
		ifs.open(file_name, ios::binary);
		int x = 10;
		ifs.read(reinterpret_cast<char*> (&x), sizeof(int));
		
	}
}

/*
	Displays a StudentCourses based on passed identification
*/
void GroupOfStudents::display(string id) const
{
	bool found = false;
	for (vector<StudentCourses>::const_iterator it = this->st_vec.begin(); it != this->st_vec.end(); ++it) {
		
		if (it->get_student().get_id().compare(id) == 0)
		{
			it->display();
			found = true;
			break;
		}
	}

	if (!found)
		cout << "Student with given identification not found!";
}

/*
	Displays StudentCourses with highest total score
*/
void GroupOfStudents::display_highest() const
{
	vector<StudentCourses> sorted = this->st_vec;
	MergeSort::sortGroupOfStudentsByScore(sorted);

	if (sorted.size() > this->NUM_BEST)
		sorted.resize(this->NUM_BEST);

	cout << "===Highest GroupOfStudents===" << endl;
	for (vector<StudentCourses>::const_iterator it = sorted.begin(); it != sorted.end(); ++it) {
		it->display();
	}
}

/*
	Displays GroupOfStudnets sorted by Student last name
*/
void GroupOfStudents::display_sorted() const
{
	vector<StudentCourses> sorted = this->st_vec;
	MergeSort::sortGroupOfStudentsByLastName(sorted);

	cout << "===Sorted GroupOfStudents===" << endl;
	for (vector<StudentCourses>::const_iterator it = sorted.begin(); it != sorted.end(); ++it) {
		it->display();
	}
}

/*
	Displays a whole GroupOfStudents
*/
void GroupOfStudents::display_all() const
{
	cout << "===All GroupOfStudents===" << endl;
	for (vector<StudentCourses>::const_iterator it = this->st_vec.begin(); it != this->st_vec.end(); ++it) {
		it->display();
	}
}

/*
	Wirtes GroupOfStudents to file
*/
void GroupOfStudents::write_to_file(string file_name)
{
	ofstream ofs;
	ofs.open(file_name, ofstream::out);
	ofs << *this;
}

/*
	Checks if GroupOfStudents is empty
*/
bool GroupOfStudents::is_empty() const
{
	return this->st_vec.empty();
}

istream &operator>>(istream &in, GroupOfStudents &gs)
{
	vector<StudentCourses> st_vec;
	StudentCourses sc;

	while (!in.eof())
	{
		in >> sc;
		st_vec.push_back(sc);
	}

	gs.st_vec = st_vec;

	return in;
}

ostream &operator<<(ostream &out, GroupOfStudents &gs)
{
	for (vector<StudentCourses>::iterator it = gs.st_vec.begin(); it != gs.st_vec.end(); ++it) {
		out << *it;
	}

	return out;
}
