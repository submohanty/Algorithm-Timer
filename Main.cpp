#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
#include "BST.h"
#include "Graph.h"

using namespace std;

void die(string message)
{
	cout << message << endl;
	exit(0);
}
string removeSpecialCharacters(string s)
{
	for (int i = 0; i < s.size(); i++)
	{

		// Finding the character whose
		// ASCII value fall under this
		// range
		if ((s[i] < 'A' || s[i] > 'Z') &&
			(s[i] < 'a' || s[i] > 'z'))
		{
			// erase function to erase
			// the character
			s.erase(i, 1);
			i--;
		}
	}
	return s;
}

int PopulateBST(BST *bst, string filename)
{
	ifstream file(filename);

	// non-existant or corrupted file
	if (file.fail())
	{
		die("Check if file exists!");
	}

	string title, word, line;
	int count;
	while (std::getline(file, line, ' '))
	{
		line = removeSpecialCharacters(line);

		count = bst->addWordNode(line);
	}
	return count;
}

int main(int argc, const char *argv[])
{

	BST bst;
	Graph g1;
	string filename(argv[1]);
	int count = 0;
	count = PopulateBST(&bst, filename);
	g1.buildVerticesFromGraphHelper(&bst);
	g1.buildEdgesFromGraphHelper(&bst);
	g1.displayEdges();

	// Project Test Cases

	// Depth First Search Recursive
	string name;
	cin >> name;
	auto t1 = Clock::now();
	g1.DFS(name);
	auto t2 = Clock::now();
	std::cout << "Delta t2-t1: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanoseconds" << std::endl;
	//https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
	//

	// Depth First Search Iterative
	string name2;
	cin >> name2;
	auto t3 = Clock::now();
	g1.DFSIterative(name);
	auto t4 = Clock::now();
	std::cout << "Delta t4-t3: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
			  << " nanoseconds" << std::endl;

	// Dijkstras
	string v1;
	cin >> v1;
	auto t5 = Clock::now();
	g1.dijkstras(v1);
	auto t6 = Clock::now();
	std::cout << "Delta t6-t5: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
			  << " nanoseconds" << std::endl;
	
	// Breadth First Search
	string vStart;
	string vEnd;
	cin >> vStart;
	cin >> vEnd;
	auto t7 = Clock::now();
	g1.BFS(vStart, vEnd);
	auto t8 = Clock::now();
	std::cout << "Delta t8-t7: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count()
			  << " nanoseconds" << std::endl;

	// Prim's

	// Topological Sort

	
	return 0;
}
