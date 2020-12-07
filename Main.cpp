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
	ifstream file;
	file.open(argv[1]);
	if(!file){
		cout << "The file was not able to be opened. Check the file name, and make sure the file is in the same directory as Main.cpp" << endl;
		return 0;
	}
	// build college linked list
	College collegelist;
	string lineInCollegeList;
	string wordInCollegeList;
	while(getline(file, lineInCollegeList, ',')){
		stringstream ss(lineInCollegeList);
		getline(ss,wordInCollegeList);
	}

	// build student BST

	// menu
	string menu = "======Main Menu======\n"
				   "1. \n"
				   "2. \n"
				   "3. \n"
				   "4. \n"
				   "5. \n";

	if (argc < 2)
	{
		cout << "Make sure to add a filename when you run the program!" << endl;
	}

	int choice = 0;
	bool done = false;

	std::string filename(argv[1]);
	do
	{
		cout << menu;
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