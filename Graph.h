#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include "BST.h"
using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
    bool visited = false;
    int distance = 0;
    vertex *parent = nullptr;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
		void buildVerticesFromGraphHelper(BST *node);
		void buildEdgesFromGraphHelper(BST *node);
		void displayG();
		// Project functions start
		void DFS(string name); // done
		void DFSHelper(vertex *v); // done
		void DFSIterative(string name); // done
		vertex* minimumDistanceNotVisited(); // done
		bool visited(); // done
		void dijkstras(string v1); // done
		void prim(string name);
		void topologicalSort();
		void topologicalSortHelper(int currentIndex, bool visited[], stack<int>& myStack);
        vertex* BFS(std::string v1, std::string v2);
		// Project functions end

    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;
        vertex* search(std::string v);
		void buildVerticesFromGraph(BSTNode *node);
		void buildEdgesFromGraph(BSTNode *node);
};

#endif // GRAPH_H
