//============================================================================
// File Name   : Courses.h
// Authors     : Sara Miketek
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef COURSES_H_
#define COURSES_H_

#include <vector>

using std::vector;
using std::istream;

// Represents a course with homeworks, quizzes, test and results
class Courses
{
public:
	static const int NUM_QUIZZES = 10;
	static const int NUM_HW = 6;
	static const int NUM_TESTS = 4;

private:
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	double final_score;
	char letter_grade;

	// Invalid data exception
	struct InvalidData : std::runtime_error {
		InvalidData() : runtime_error("Invalid input data format") {}
	};

public:
	// Initializes empty Courses
	Courses();

	// Destructs Courses object
	~Courses();

	// Initializes Courses with parameters
	Courses(const vector<int> &quiz, const vector<int> &homework, const vector<int> &test);

	// Returns a final score of course
	double get_final_score() const;

	// Returns a letter grade of course
	char get_letter_grade() const;

	// Displays a course results on standard output
	void display() const;

	// Calculates the final score
	void calc_final_score();

	// Calculates a letter grade
	void calc_letter_grade();

	friend istream &operator>> (istream &in, Courses &courses);
};


#endif /*COURSES_H_*/
