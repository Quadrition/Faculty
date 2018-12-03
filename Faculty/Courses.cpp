//============================================================================
// File Name   : Courses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "Courses.h"
#include <iostream>
#include <sstream>
#include "Menu.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

static const double QUIZ_WEIGHT = 0.05;
static const double HOMEWORK_WEIGHT = 0.5;
static const double TEST_WEIGHT = 0.45;

/*
	Courses empty constructor
*/
Courses::Courses() : quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS)
{
}

/*
	Courses destructor
*/
Courses::~Courses()
{
}

/*
	Courses constructor with parameters
*/
Courses::Courses(const vector<int> &quiz, const vector<int> &homework, const vector<int> &test) : quiz(quiz), homework(homework), test(test), final_score(0), letter_grade('F')
{
}

/*
	Returns a final score of course
*/
double Courses::get_final_score() const
{
	return this->final_score;
}

char Courses::get_letter_grade() const
{
	return this->letter_grade;
}

/*
	Displays a course results on standard output
*/
void Courses::display() const
{
	cout << "=Courses=" << endl;
	cout << "Final score: " << this->final_score << endl;
	cout << "Letter grade: " << this->letter_grade << endl;
}

/*
	Calculates the final score
*/
void Courses::calc_final_score()
{
	double final_score = 0, quiz = 0, homework = 0, test = 0;

	// Calculating quiz results
	for (vector<int>::iterator it = this->quiz.begin(); it != this->quiz.end(); ++it) 
	{
		if (!(0 <= *it <= 100))
			throw InvalidData();

		quiz += *it;
	}
	final_score += QUIZ_WEIGHT * quiz / this->NUM_QUIZZES;

	// Calculating homework results
	for (vector<int>::iterator it = this->homework.begin(); it != this->homework.end(); ++it)
	{
		if (!(0 <= *it <= 100))
			throw InvalidData();

		homework += *it;
	}
	final_score += HOMEWORK_WEIGHT * homework / this->NUM_HW;

	// Calculating test results
	for (vector<int>::iterator it = this->test.begin(); it != this->test.end(); ++it)
	{
		if (!(0 <= *it <= 100))
			throw InvalidData();

		test += *it;
	}
	final_score += TEST_WEIGHT * test / this->NUM_TESTS;

	this->final_score = final_score;
}

/*
	Calculates a letter grade
*/
void Courses::calc_letter_grade()
{
	// Score must be between 0 and 100
	if (this->final_score > 100)
		throw InvalidData();
	else if (this->final_score > 90)
		this->letter_grade = 'A';
	else if (this->final_score > 80)
		this->letter_grade = 'B';
	else if (this->final_score > 70)
		this->letter_grade = 'C';
	else if (this->final_score > 60)
		this->letter_grade = 'D';
	else if (this->final_score > 50)
		this->letter_grade = 'E';
	else if (this->final_score >= 0)
		this->letter_grade = 'F';
	else
		throw InvalidData();
}

istream &operator>>(istream &in, Courses &courses)
{
	string line;
	vector<int> homework, test, quiz;
	int score;

	// Getting homework scores (1 line)
	{
		getline(in, line);
		stringstream stream(line);
		for (int i = 0; i < courses.NUM_HW; i++)
		{
			stream >> score;

			if (stream.fail())
				throw Menu::InvalidData();

			homework.push_back(score);
		}
	}

	// Getting test scores (1 line)
	{
		getline(in, line);
		stringstream stream(line);
		for (int i = 0; i < courses.NUM_TESTS; i++)
		{
			stream >> score;

			if (stream.fail())
				throw Menu::InvalidData();

			test.push_back(score);
		}
	}
	
	// Getting quiz scores (1 line)
	{
		getline(in, line);
		stringstream stream(line);
		for (int i = 0; i < courses.NUM_QUIZZES; i++)
		{
			stream >> score;

			if (stream.fail())
				throw Menu::InvalidData();

			quiz.push_back(score);
		}
	}

	courses.homework = homework;
	courses.quiz = quiz;
	courses.test = test;

	return in;
}
