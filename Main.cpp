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

	cout << "Welcome to the compare graph functions project." << endl; 
	g1.displayEdges();
	cout << "The graph is setup in that it each vertex has a list of adjacencies connected after the arrow, listed as\nVERTEX-->CONNECTEDVERTEX***CONNECTEDVERTEX , and so forth." << endl;
	cout << "Look at the first word in each line, and enter in a word to check the runtime of.\nDO NOT REPEAT WORDS" << endl;
	// Project Test Cases
	// Depth First Search Recursive -- working
	cout << "Enter in a word to check the runtime for a Recursive Depth First Search" << endl;
	string name;
	cin >> name;
	auto t1 = Clock::now();
	g1.DFS(name);
	auto t2 = Clock::now();
	std::cout << "Recursive Depth First Search: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			  << " nanoseconds" << std::endl;
	//https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
	//

	// Depth First Search Iterative -- not working
	cout << "Enter in a word to check the runtime for an Iterative Depth First Search" << endl;
	string name2;
	cin >> name2;
	auto t3 = Clock::now();
	g1.DFSIterative(name2);
	auto t4 = Clock::now();
	std::cout << "Iterative Depth First Search: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
			  << " nanoseconds" << std::endl;

	// Dijkstras -- working
	cout << "Enter in a word to check the runtime for the Dijkstra's algorithm" << endl;
	string v1;
	cin >> v1;
	auto t5 = Clock::now();
	g1.dijkstras(v1);
	auto t6 = Clock::now();
	std::cout << "Dijkstra's: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
			  << " nanoseconds" << std::endl;
	
	// Breadth First Search -- works when there isn't any repeats
	cout << "Enter in a word to check the runtime for the Breadth First Search - shortest path: " << endl;
	string vStart;
	string vEnd;
	cin >> vStart;
	cin >> vEnd;
	auto t7 = Clock::now();
	g1.BFS(vStart, vEnd);
	auto t8 = Clock::now();
	std::cout << "Breadth First Search - Shortest Path: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count()
			  << " nanoseconds" << std::endl;

	// Standard Breadth First Traversal -- works when there isn't any repeats
	cout << "Enter in a word to check the runtime for the Breadth First Traversal: " << endl;
	string bft;
	cin >> bft;
	auto t9 = Clock::now();
	g1.BFSTraversal(bft);
	auto t10 = Clock::now();
	std::cout << "Breadth First Traversal: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count()
			  << " nanoseconds" << std::endl;

	cout << "Now the BST Stuff: " << endl;
	cout << "The maximum value in the BST is " << endl;
	bst.maxBST();
	cout << "The minimum value in the BST is " << endl;
	bst.minBST();
	string option;
	cout << "How would you like your BST printed?\na. PostOrder\nb. PreOrder\nc.InOrder\n--Enter in just the letter--" << endl;
	cin >> option;
	if(option == "a"){
		bst.printPostOrderBST();
	}
	else if(option == "b"){
		bst.printPreOrderBST();
	}
	else if(option == "c"){
		bst.printInOrderBST();
	}
	return 0;
}
