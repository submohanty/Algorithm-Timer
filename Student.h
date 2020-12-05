#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// store each student in a BST based on their name
// the BST sorts students by their name

struct StandardizedTests
{
	vector<int> SATScores;
	vector<int> ACTScores;
};

struct Clubs
{
};

struct StudentNode
{
	// BST stuff
	StudentNode *parent;
	StudentNode *left;
	StudentNode *right;
	// General information
	string name;
	int age;
	int gradeInSchool;
	// Academics
	vector<StandardizedTests> testScores;

	StudentNode(StudentNode *parent1, StudentNode *left1, StudentNode *right1, string name1, int age1, int gradeInSchool1)
	{
		parent = parent1;
		left = left1;
		right = right1;
		name = name1;
		age = age1;
		gradeInSchool = gradeInSchool1;
	}
};

class Student
{
public:
private:
};

#endif