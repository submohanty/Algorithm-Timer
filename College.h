#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#ifndef COLLEGE_H
#define COLLEGE_H

struct College1
{
	// Linked List stuff
	College1 *next;
	College1 *previous;
	// College stuff
	string name;
	vector<string> subcolleges; // engineering, arts, etc.
	double costPerYear;			// a number
	string location;			// city and state
	int rank;					// US News ranking of best colleges
	// Academics
	double minGPA;
	int minSAT;
	int minACT;
};

class College
{
public:
	void buildLL(); // builds the college list
	void displayCollegeInformation(College1 *collegeToShow);														// cout information about the college chosen
	void addToPersonalCollegeList();																				// adds college to your own separate linked list of your favorite colleges
	void personalCollegeListTXT();																					// outputs a txt file with your personal list
	College1 *selectCollege();																						// selects a college from the list of colleges
private:
	College1 *head;				// head of the linked list of colleges
	College1 *headPersonalList; // head of the personally chosen linked list of colleges
};

#endif