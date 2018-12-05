//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Petar Cerovic
// Version     : 1.4
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "GroupOfStudents.h"
#include <iostream>
#include <fstream>
#include "MergeSort.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

/*
	Initializes array of Students object
*/
GroupOfStudents::GroupOfStudents()
{
}

/*
	Destructs array of Students
*/
GroupOfStudents::~GroupOfStudents()
{
}

/*
	Initializes array of Students with courses
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
void GroupOfStudents::read_from_file(string file_name, string extension)
{
	if (extension.compare("bin") == 0)
	{
		this->read_from_file_binary(file_name + "." + extension);
	}
	else
	{
		this->read_from_file_text(file_name + "." + extension);
	}
}

/*
	Reads GroupOfStudents from binary file
*/
void GroupOfStudents::read_from_file_binary(string file_name)
{
	ifstream ifs;

	vector<StudentCourses> scs;

	ifs.open(file_name, ios::binary);
	int size_first_name, size_last_name, size_id;

	ifs.seekg(0, ios::end);
	int size = (int)ifs.tellg();
	ifs.seekg(0, ios::beg);

	while (ifs.tellg() < size)
	{
		ifs.read(reinterpret_cast<char*> (&size_first_name), sizeof(int));
		char* first_name = new char[size_first_name];
		ifs.read(first_name, size_first_name * sizeof(char));
		ifs.read(reinterpret_cast<char*> (&size_last_name), sizeof(int));
		char* last_name = new char[size_last_name];
		ifs.read(last_name, size_last_name * sizeof(char));
		ifs.read(reinterpret_cast<char*> (&size_id), sizeof(int));
		char* id = new char[size_id];
		ifs.read(id, size_id * sizeof(char));

		string first(first_name);
		string last(last_name);
		string i(id);
		Student student(first, last, i);

		vector<int> homework;
		vector<int> quizz;
		vector<int> test;
		for (int i = 0; i < Courses::NUM_HW; i++)
		{
			int result;
			ifs.read(reinterpret_cast<char*> (&result), sizeof(int));
			homework.push_back((int)result);
		}

		for (int i = 0; i < Courses::NUM_TESTS; i++)
		{
			int result;
			ifs.read(reinterpret_cast<char*> (&result), sizeof(int));
			test.push_back((int)result);
		}

		for (int i = 0; i < Courses::NUM_QUIZZES; i++)
		{
			int result;
			ifs.read(reinterpret_cast<char*> (&result), sizeof(int));
			quizz.push_back((int)result);
		}

		Courses courses(quizz, homework, test);
		courses.calc_final_score();
		courses.calc_letter_grade();
		StudentCourses sc(student, courses);
		scs.push_back(sc);
	}

	this->st_vec = scs;
}

/*
	Reads GroupOfStudents from text file
*/
void GroupOfStudents::read_from_file_text(string file_name)
{
	ifstream ifs;

	ifs.open(file_name);
	ifs >> *this;
	ifs.close();
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
void GroupOfStudents::write_to_file(string file_name, string extension)
{
	if (extension.compare("bin") == 0)
	{
		this->write_to_text_file(file_name + "." + extension);
		this->write_to_binary_file(file_name + "." + extension);
	}
	else
		this->write_to_text_file(file_name + "." + extension);
}

/*
	Wirtes GroupOfStudents to binary file
*/
void GroupOfStudents::write_to_binary_file(string file_name)
{
	ofstream ofs;

	ofs.open(file_name, ios::binary);
	int size;

	for (vector<StudentCourses>::const_iterator it = this->st_vec.begin(); it != this->st_vec.end(); ++it) {
		size = it->get_student().get_first_name().length() + 1;
		ofs.write(reinterpret_cast<char*> (&size), sizeof(int));
		ofs.write(it->get_student().get_first_name().c_str(), size * sizeof(char));
		size = it->get_student().get_last_name().length() + 1;
		ofs.write(reinterpret_cast<char*> (&size), sizeof(int));
		ofs.write(it->get_student().get_last_name().c_str(), size * sizeof(char));
		size = it->get_student().get_id().length() + 1;
		ofs.write(reinterpret_cast<char*> (&size), sizeof(int));
		ofs.write(it->get_student().get_id().c_str(), size * sizeof(char));

		for (int i = 0; i < it->get_courses().homework.size(); i++)
		{
			ofs.write(reinterpret_cast<char*> (&it->get_courses().homework[i]), sizeof(int));
		}

		for (int i = 0; i < it->get_courses().test.size(); i++)
		{
			ofs.write(reinterpret_cast<char*> (&it->get_courses().test[i]), sizeof(int));
		}

		for (int i = 0; i < it->get_courses().quiz.size(); i++)
		{
			ofs.write(reinterpret_cast<char*> (&it->get_courses().quiz[i]), sizeof(int));
		}
	}
	ofs.close();
}

/*
	Wirtes GroupOfStudents to text file
*/
void GroupOfStudents::write_to_text_file(string file_name)
{
	ofstream ofs;

	ofs.open(file_name);
	ofs << *this;
	ofs.close();
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
