#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"
#include "College.h"
using namespace std;

void Student::addFriend(string v1, string v2, int weight)
{

	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].name == v1)
		{
			for (int j = 0; j < vertices.size(); j++)
			{
				if (vertices[j].name == v2 && i != j)
				{
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);
					//another vertex for edge in other direction
					adjVertex av2;
					av2.v = &vertices[i];
					av2.weight = weight;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}
}
void Student::addVertex(string n) // adds a student to the graph
{
	bool found = false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].name == n)
		{
			found = true;
			cout << vertices[i].name << " found." << endl;
		}
	}
	if (found == false)
	{
		vertex v;
		v.name = n;
		vertices.push_back(v);
	}
}

void Student::displayStudents() // display the names of all the students
{
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i].name << "-->";
		for (int j = 0; j < vertices[i].adj.size(); j++)
		{
			cout << vertices[i].adj[j].v->name;
			if (j != vertices[i].adj.size() - 1)
				cout << "***";
		}
		cout << endl;
	}
}

void Student::displayStudentInfo(vertex i) // display info of a student
{
	cout << "Name: " << i.name << endl;
	cout << "Grade: " << i.grade << endl;
	cout << "GPA: " << i.gpa << endl;
	cout << "Test Score: " << i.testScore << endl;
}

void Student::topStudent() // get the info of the top student in the class
{
	int iteratorIndex = vertices[0].gpa * vertices[0].testScore;
	vertex iterator = vertices[0];
	for (int i = 0; i < vertices.size(); i++)
	{
		if (iteratorIndex = vertices[i].gpa * vertices[i].testScore > iteratorIndex)
		{
			iteratorIndex = vertices[i].gpa * vertices[i].testScore;
			iterator = vertices[i];
		}
	}
	cout << "The top student from the class is: " << endl;
	displayStudentInfo(iterator);
}

void Student::modifyStudent(string name) // enter in a student's name, and edit some part of their data
{
	for (int x = 0; x < vertices.size(); x++)
	{
		if (vertices[x].name == name)
		{
			cout << "What piece of data would you like to change?\n" << "a. name\nb. grade\nc. gpa\nd. testscore" << endl;
			string dataChange;
			cin >> dataChange;
			if(dataChange == "a"){
				cout << "Enter in the student's new name" << endl;
				string newName;
				cin >> newName;
				vertices[x].name = newName;
				return;
			}
			if(dataChange == "b"){
				cout << "Enter in the student's new grade" << endl;
				int newGrade;
				cin >> newGrade;
				vertices[x].grade = newGrade;
				return;
			}
			if(dataChange == "c"){
				cout << "Enter in the student's new gpa" << endl;
				double newGPA;
				cin >> newGPA;
				vertices[x].gpa = newGPA;
				return;
			}
			if(dataChange == "d"){
				cout << "Enter in the student's new test score" << endl;
				double newTest;
				cin >> newTest;
				vertices[x].testScore = newTest;
				return;
			}
		}
	}
}

