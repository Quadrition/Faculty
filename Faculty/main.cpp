//============================================================================
// File Name   : main.cpp 
// Authors     : Various
// Version     : 1.1
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include <iostream>
#include <fstream>
#include "Menu.h"
#include <filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

static const string OUTPUT_DEFALUT = "output";

int main(int argc, char **argv)
{
	if (argc != 3 && argc != 4)
	{
		cout << "Bad command arguments!";
		return 1;
	}
	string extension(argv[1]);
	if (extension.compare("bin") != 0 && extension.compare("txt") != 0)
	{
		cout << "Invalid file extension!";
		return 1;
	}
	string inputPath = argv[2];
	string outputPath;
	if (inputPath.substr(inputPath.length() - 3) == "bin" && inputPath.substr(inputPath.length() - 3) == "txt")
	{
		cout << "File extension of full output path is different from extension passed as first argument!";
		return 1;
	}
	if (argc == 4)
	{
		outputPath = argv[3];

		if (outputPath.substr(outputPath.length() - 3) == "bin" && outputPath.substr(outputPath.length() - 3) == "txt")
		{
			cout << "File extension of full input path is different from extension passed as first argument!";
			return 1;
		}
	}
	else
	{
		int last = inputPath.find_last_of("/\\");
		outputPath = inputPath.substr(0, last + 1) + OUTPUT_DEFALUT + "." + extension;
	}

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
				m.read_students(inputPath, extension);
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
			m.write_students(argv[3], extension);
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
