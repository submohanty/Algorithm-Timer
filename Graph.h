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
		void DFS(string name); 
		void DFSHelper(vertex *v);
		void DFSIterative(string name);
		vertex* minimumDistanceNotVisited(); 
		bool visited(); 
		void dijkstras(string v1); 
		void BFSTraversal(string v);
        vertex* BFS(std::string v1, std::string v2);
    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;
        vertex* search(std::string v);
		void buildVerticesFromGraph(BSTNode *node);
		void buildEdgesFromGraph(BSTNode *node);
};

#endif // GRAPH_H
