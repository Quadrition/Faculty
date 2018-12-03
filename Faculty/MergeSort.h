//============================================================================
// File Name   : MergeSort.h
// Authors     : Sara Miketek
// Version     : 1.0
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
	static void mergeSortGroupOfStudentsByLastName(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses> &bars);
	static void mergeSortGroupOfStudentsByScore(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses>& bars);
public:
	static void sortGroupOfStudentsByLastName(vector<StudentCourses> &sc);
	static void sortGroupOfStudentsByScore(vector<StudentCourses> &sc);
};

#endif /*MERGESORT_H_*/
