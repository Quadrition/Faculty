//============================================================================
// File Name   : main.cpp 
// Authors     : Various
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	Menu m;
	int option;
	m.display_menu(false);

	do
	{
		cout << "> ";
		while (!(cin >> option) || option < 1 || option > Menu::EXIT)
		{
			if (cin.fail())	// we found something that wasn’t an integer
			{
				cin.clear();	// we’d like to look at the characters
				char ch;
				while (cin >> ch && !isdigit(ch))
				{
					cerr << "Invalid input; please try again" << endl;
					cout << "> ";
				}
				cin.unget();
			}
			else
			{	// option < 1 || option > Menu::EXIT */
				cerr << "Invalid input; please try again" << endl;
				cout << "> ";
			}
		}

		switch (option)
		{
		case Menu::INFO:
			m.display_info();
			break;
		case Menu::READ_FILE:
			try
			{
				m.read_students(argv[1]);
			}
			catch (const Menu::InvalidFile& excp)
			{
				cerr << excp.what() << endl;
			}
			catch (const Menu::InvalidData& excp)
			{
				cerr << excp.what() << endl;
			}
			break;
		case Menu::DISPLAY:
			m.display_students();
			break;
		case Menu::HIGHEST:
			m.display_highest_score();
			break;
		case Menu::DISPLAY_SORTED:
			m.display_students_sorted();
			break;
		case Menu::DISPLAY_ALL:
			m.display_all_students();
			break;
		case Menu::WRITE_FILE:
			m.write_students("output.bin");
			break;
		case Menu::EXIT:
			option = Menu::EXIT;
			break;
		default:
			cerr << "Invalid input; please try again" << endl;
			break;
		}
		m.display_menu(true);
	} while (option != Menu::EXIT);
	return 0;
}
