//============================================================================
// File Name   : Menu.h
// Authors     : Petar Cerovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include "GroupOfStudents.h"

using std::string;

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData() : runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile() : runtime_error("Invalid input file name") {}
	};

	enum OPTIONS { INFO = 1, READ_FILE, DISPLAY, HIGHEST, DISPLAY_SORTED, DISPLAY_ALL, WRITE_FILE, EXIT };

private:
	GroupOfStudents gs;

public:
	Menu() {}

	// Checks if student id is valid
	bool is_id_valid(string id) const;

	// Displays menu items with choices
	void display_menu(bool new_line) const;

	// Displays information about project authors
	void display_info() const;

	// Read students from textual or binary file
	void read_students(string file_name);

	// Displays student with corresponding ID
	void display_students() const;

	// Displays all students ordered by highest score
	void display_highest_score() const;

	// Displays all students ordered by Last Name
	void display_students_sorted() const;

	// Displays all students
	void display_all_students() const;

	// Write students into textual or/and binary files
	void write_students(string file_name);
};

#endif /*MENU_H_*/
