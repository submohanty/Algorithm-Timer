#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "College.h"
using namespace std;

void College::displayCollegeInformation(College1 *collegeToShow)
{ // cout information about the college chosen
	cout << "---" << endl;
	cout << "Name: " << collegeToShow->name << endl;
	cout << "Location: " << collegeToShow->location << endl;
	cout << "Cost per year ($):" << collegeToShow->costPerYear << endl;
	cout << "Rank (U.S. News 2020-2021 Best Colleges Ranking): " << collegeToShow->rank << endl;
	cout << "Subcolleges/Programs of Study: ";
	for (int i = 0; i < collegeToShow->subcolleges.size(); i++)
	{
		cout << collegeToShow->subcolleges[i] << " ";
	}
	cout << endl;
	cout << "Extracurriculars: ";
	for (int j = 0; j < collegeToShow->extracurriculars.size(); j++)
	{
		cout << collegeToShow->extracurriculars[j] << " ";
	}
	cout << endl;
	cout << "Academic Requirements:" << endl;
	cout << "Average GPA of students accepted: " << collegeToShow->minGPA << endl;
	cout << "Average SAT score of students accepted: " << collegeToShow->minSAT << endl;
	cout << "Average ACT score of students accepted: " << collegeToShow->minACT << endl;
	cout << "---" << endl;
}

void College::addToPersonalCollegeList()
{ // adds college to your own separate linked list of your favorite colleges
	College1 *collegeToAddToList = selectCollege();
	College1 *iterator = headPersonalList;
	while (iterator->next != nullptr)
	{
		iterator = iterator->next;
	}
	iterator->next = collegeToAddToList; // add the college to the end of the personal list
}

College1 *College::selectCollege()
{
	cout << "Select the college you want from this list:" << endl;
	College1 *iterator1 = head;
	while (iterator1->next != nullptr) // print out the names of all the colleges
	{
		cout << iterator1->name << endl;
		iterator1 = iterator1->next;
	}
	cout << "Enter in the name of the college: ";
	string nameCol;
	cin >> nameCol;
	College1 *lastIterator = head;
	while(lastIterator->next != nullptr){
		if(lastIterator->name == nameCol){
			return lastIterator; // finds the college with the right name and returns it
		}
	}
	return lastIterator; // if something goes wrong just return it
}