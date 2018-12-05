//============================================================================
// File Name   : MergeSort.h
// Authors     : Sara Miketek
// Version     : 1.1
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "StudentCourses.h";

using std::vector;

static class MergeSort
{
private:

	// Sorts students by Last Name
	static void mergeSortGroupOfStudentsByLastName(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses> &bars);

	// Sorts students by highest score
	static void mergeSortGroupOfStudentsByScore(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses>& bars);

public:

	// Checks and calls function for sorting Students by last name
	static void sortGroupOfStudentsByLastName(vector<StudentCourses> &sc);

	// Checks and calls function for sorting Students by highest score
	static void sortGroupOfStudentsByScore(vector<StudentCourses> &sc);
};

#endif /*MERGESORT_H_*/
