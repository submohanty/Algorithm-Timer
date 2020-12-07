#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "College.h"
#include "Student.h"
using namespace std;

int main(int argc, char *argv[])
{
	// build college linked list

	// build student BST

	// menu
	string dmenu = "======Main Menu======\n"
				   "1. Print vertices\n"
				   "2. Assign Groups\n"
				   "3. Infect and Trace\n"
				   "4. Infect and Spread\n"
				   "5. Quit\n";

	if (argc < 2)
	{
		cout << "Make sure to add a filename when you run the program!" << endl;
	}

	int choice = 0;
	bool done = false;

	std::string filename(argv[1]);
	do
	{
		cout << dmenu;
		cin >> choice;

		// flush the newlines and other characters
		cin.clear();
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 6:
		default:
		{
			done = true;
			break;
		}
		}

	} while (!done);

	cout << "Goodbye!" << endl;
	return 0;

	return 0;
}