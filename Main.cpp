// All of the header files required to make the program run
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock; //https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
#include "BST.h"
#include "Graph.h"
using namespace std;

void die(string message) // simple function to exit the program and print out an error message
{
	cout << message << endl;
	exit(0);
}
string removeSpecialCharacters(string s) // function to only take in values in the test.txt file that are between 'A' to 'Z' and 'a' to 'z' on the ASCII table
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

int PopulateBST(BST *bst, string filename) // function to take in a BST and the name of a text file, and turn the words in the text file into words as part of a BST
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
	// Creating objects of our two classes, BST and Graph
	BST bst;
	Graph g1;
	// ---------------------------------------------------------------------------------------------
	// Taking in our file name, and then using it to make the BST
	string filename(argv[1]);
	int count = 0;
	count = PopulateBST(&bst, filename);
	// ---------------------------------------------------------------------------------------------
	// Now that the BST has values, we use the BST to recursively go through and add these nodes to the Graph, with vertices and edges
	g1.buildVerticesFromGraphHelper(&bst);
	g1.buildEdgesFromGraphHelper(&bst);
	// ---------------------------------------------------------------------------------------------
	// Instructions //
	g1.displayEdges(); // The graph is shown, with vertices and their edges with the vertices adjacent to them. This is useful for the user picking which vertex to go to
	cout << "Welcome to the compare graph functions project." << endl;
	cout << "The graph is setup in that it each vertex has a list of adjacencies connected after the arrow, listed as\nVERTEX-->CONNECTEDVERTEX***CONNECTEDVERTEX , and so forth." << endl;
	cout << "Look at the first word in each line, and enter in a word to check the runtime of.\nDO NOT REPEAT WORDS" << endl;
	// ---------------------------------------------------------------------------------------------
	// Depth First Search Recursive - does the depth first search algorithm recursively
	cout << "Enter in a word from the Graph above to check the runtime for a Recursive Depth First Search" << endl;
	string name;
	cin >> name;
	auto t1 = Clock::now(); // this starts the clock
	g1.DFS(name);
	auto t2 = Clock::now(); // this ends the clock
	std::cout << "Recursive Depth First Search: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() // this prints out how long it took for the algorithm to run
			  << " nanoseconds" << std::endl;
	// ---------------------------------------------------------------------------------------------
	// Depth First Search Iterative -  does the depth first search algorithm iteratively - however, there is a bug here that is causing it to consistently return 0 nanosecond runtime
	cout << "Enter in a word to check the runtime for an Iterative Depth First Search" << endl;
	string name2;
	cin >> name2;
	auto t3 = Clock::now();
	g1.DFSIterative(name2);
	auto t4 = Clock::now();
	std::cout << "Iterative Depth First Search: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
			  << " nanoseconds" << std::endl;
	// ---------------------------------------------------------------------------------------------
	// Dijkstra's - does the Dijkstra's algorithm
	cout << "Enter in a word to check the runtime for the Dijkstra's algorithm" << endl;
	string v1;
	cin >> v1;
	auto t5 = Clock::now();
	g1.dijkstras(v1);
	auto t6 = Clock::now();
	std::cout << "Dijkstra's: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
			  << " nanoseconds" << std::endl;
	// ---------------------------------------------------------------------------------------------
	// Breadth First Search - shortest path - Does the breadth first search shortest path algorithm. You must enter in two unique vertices, and make sure that the vertex does not include the other as an adjacent vertex
	cout << "Enter in two words to check the runtime for the Breadth First Search - shortest path: " << endl;
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
	// ---------------------------------------------------------------------------------------------
	// Standard Breadth First Traversal - Does the breadth first search shortest path algorithm. You must enter in a unique vertex, and make sure that the vertex does not include any of the other vertices you have entered as an adjacent vertex
	cout << "Enter in a word to check the runtime for the Breadth First Traversal: " << endl;
	string bft;
	cin >> bft;
	auto t9 = Clock::now();
	g1.BFSTraversal(bft);
	auto t10 = Clock::now();
	std::cout << "Breadth First Traversal: "
			  << std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count()
			  << " nanoseconds" << std::endl;
	// ---------------------------------------------------------------------------------------------
	cout << "Now the BST Stuff: " << endl;
	cout << "The maximum value in the BST is " << endl;
	bst.maxBST(); // prints out the node in the BST with the highest count
	cout << "The minimum value in the BST is " << endl;
	bst.minBST(); // prints out the node in the BST with the lowest count
	// ---------------------------------------------------------------------------------------------
	string option;
	cout << "How would you like your BST printed?\na. PostOrder\nb. PreOrder\nc. InOrder\n--Enter in just the letter--" << endl;
	cin >> option;
	if (option == "a")
	{
		bst.printPostOrderBST(); // prints out the BST in the post order method
	}
	else if (option == "b")
	{
		bst.printPreOrderBST(); // prints out the BST in the pre order method
	}
	else if (option == "c")
	{
		bst.printInOrderBST(); // prints out the BST in the in order method
	}
	return 0;
}
// ---------------------------------------------------------------------------------------------