#include "Menu.h"
//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

bool Menu::is_id_valid(string id) const
{
	return false;
}

void Menu::display_menu(bool new_line) const
{
	if (new_line)
		cout << endl << endl;

	cout << "=====Menu=====" << endl;
	cout << "1. Display info" << endl;
	cout << "2. Read students" << endl;
	cout << "3. Display students" << endl;
	cout << "4. Display students with highest score" << endl;
	cout << "5. Display sorted students" << endl;
	cout << "6. Display all students" << endl;
	cout << "7. Write students" << endl;
	cout << "8. Exit" << endl;
}

void Menu::display_info() const
{
	cout << "====Info====" << endl;
	cout << "Authors:" << endl;
	cout << "Petar Cerovic SW26-2017" << endl;
	cout << "Milan Pavlov SW??-2017" << endl;
	cout << "Sara Miketek SW62-2017" << endl;
}

void Menu::read_students(string file_name)
{
	gs.read_from_file(file_name);
}

void Menu::display_students() const
{
	if (this->gs.is_empty())
	{
		cout << "GroupOfStudents is empty!" << endl;
		return;
	}

	string id;
	cout << "Enter identification: ";
	cin >> id;
	this->gs.display(id);
}

void Menu::display_students_sorted() const
{
	if (this->gs.is_empty())
	{
		cout << "GroupOfStudents is empty!" << endl;
		return;
	}

	this->gs.display_sorted();
}

void Menu::display_highest_score() const
{
	if (this->gs.is_empty())
	{
		cout << "GroupOfStudents is empty!" << endl;
		return;
	}

	this->gs.display_highest();
}

void Menu::display_all_students() const
{
	if (this->gs.is_empty())
	{
		cout << "GroupOfStudents is empty!" << endl;
		return;
	}

	this->gs.display_all();
}

void Menu::write_students(string file_name)
{
	if (this->gs.is_empty())
	{
		cout << "GroupOfStudents is empty!" << endl;
		return;
	}

	this->gs.write_to_file(file_name);
}
