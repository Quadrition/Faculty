//============================================================================
// File Name   : MergeSort.cpp
// Authors     : Sara Miketek
// Version     : 1.2
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "MergeSort.h"

/*
	Sorts students by Last Name
*/
void MergeSort::mergeSortGroupOfStudentsByLastName(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses>& sc)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j].get_student().get_last_name().compare(right[k].get_student().get_last_name()) == -1) {
			sc[i] = left[j];
			j++;
		}
		else {
			sc[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		sc[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		sc[i] = right[k];
		k++; i++;
	}
}

/*
	Sort students by highest score
*/
void MergeSort::mergeSortGroupOfStudentsByScore(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses>& sc)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j].get_courses().get_final_score() < right[k].get_courses().get_final_score()) {
			sc[i] = left[j];
			j++;
		}
		else {
			sc[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		sc[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		sc[i] = right[k];
		k++; i++;
	}
}

void MergeSort::mergeSortGroupOfStudentsByIndex(vector<StudentCourses>& left, vector<StudentCourses>& right, vector<StudentCourses>& sc)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j].get_student().get_id().compare(right[k].get_student().get_id()) == -1) {
			sc[i] = left[j];
			j++;
		}
		else {
			sc[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		sc[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		sc[i] = right[k];
		k++; i++;
	}
}

/*
	Checks and calls function for sorting Students by last name
*/
void MergeSort::sortGroupOfStudentsByLastName(vector<StudentCourses>& sc)
{
	if (sc.size() <= 1) return;

	int mid = sc.size() / 2;
	vector<StudentCourses> left;
	vector<StudentCourses> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(sc[j]);
	for (size_t j = 0; j < (sc.size()) - mid; j++)
		right.push_back(sc[mid + j]);

	sortGroupOfStudentsByLastName(left);
	sortGroupOfStudentsByLastName(right);
	mergeSortGroupOfStudentsByLastName(left, right, sc);
}

/*
	Checks and calls function for sorting Students by highest score
*/
void MergeSort::sortGroupOfStudentsByScore(vector<StudentCourses>& sc)
{
	if (sc.size() <= 1) return;

	int mid = sc.size() / 2;
	vector<StudentCourses> left;
	vector<StudentCourses> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(sc[j]);
	for (size_t j = 0; j < (sc.size()) - mid; j++)
		right.push_back(sc[mid + j]);

	sortGroupOfStudentsByScore(left);
	sortGroupOfStudentsByScore(right);
	mergeSortGroupOfStudentsByScore(left, right, sc);
}

void MergeSort::sortGroupOfStudentsByIndex(vector<StudentCourses>& sc)
{
	if (sc.size() <= 1) return;

	int mid = sc.size() / 2;
	vector<StudentCourses> left;
	vector<StudentCourses> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(sc[j]);
	for (size_t j = 0; j < (sc.size()) - mid; j++)
		right.push_back(sc[mid + j]);

	sortGroupOfStudentsByIndex(left);
	sortGroupOfStudentsByIndex(right);
	mergeSortGroupOfStudentsByIndex(left, right, sc);
}
