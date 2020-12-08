// Header files and stuff needed throughout
#include "BST.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor that allocates memory for the BST
BST::BST() {
    root = nullptr;
}

// Function that returns the root of the BST
BSTNode* BST::getRoot(){
    return root;
}

// Function that takes in a string, and adds it to the BST. It returns the total amount of words added to the BST, an integer
int BST::addWordNode(string word) {
    int opCounter = 0;
    BSTNode *found = searchBST(word, opCounter);
    if(found == nullptr){
        // string comparision uses std::lexicographical_compare.
        // So i can directly comapare titles.
        
        // find the insertion point
        BSTNode* temp = root;
        BSTNode* parent = nullptr;
        BSTNode *newBST = new BSTNode(word, nullptr, nullptr, nullptr);
        while(temp != nullptr) {
            parent = temp;
            if (newBST->word > temp->word)
                temp = temp->rightChild;
            else
                temp = temp->leftChild;
        }    

        // reached the bottom of the tree, add node
        if(parent == nullptr){
            root = newBST;        
        }else if(newBST->word < parent->word){
            parent->leftChild = newBST;
            newBST->parent = parent;
        }else{
            parent->rightChild = newBST;
            newBST->parent = parent;
        }

    }else{
        //cout<<"node already in tree: "<<found->word<<endl;
        found->count += 1;
    }
    return opCounter;
}

// The helper function to printInOrderBST(BSTNode *node)
void BST::printInOrderBST() {
    if (!root) {
        return;
    }
    printInOrderBST(root);
}

// Function that prints out the nodes' words of the BST in-order
void BST::printInOrderBST(BSTNode *node) {
    if (!node) {
        return;
    }
    
    printInOrderBST(node->leftChild);   
    cout << node->word<<endl;
    printInOrderBST(node->rightChild);
}

// The helper function to printPreOrderBST(BSTNode *node)
void BST::printPreOrderBST() {
    if (!root) {
        return;
    }
    printPreOrderBST(root);
}

// Function that prints out the nodes' words of the BST pre-order
void BST::printPreOrderBST(BSTNode *node) {
    if (!node) {
        return;
    }
    cout << node->word<<endl;
    if(node != root){
        cout<<"parent: "<<node->parent->word<<endl;

    }
    if(node->leftChild != nullptr){
        cout<<"left: "<<node->leftChild->word<<endl;
    }
    if(node->rightChild != nullptr){
        cout<<"right: "<<node->rightChild->word<<endl;
    }
    printPreOrderBST(node->leftChild);   
    printPreOrderBST(node->rightChild);
}

// The helper function to printPostOrderBST(BSTNode *node);
void BST::printPostOrderBST(){
	if(!root){
		return;
	}
	printPostOrderBST(root);
}

// Function that prints out the nodes' words of the BST post-order
void BST::printPostOrderBST(BSTNode *node){
	if(!node){
		return;
	}
	if(node->leftChild != nullptr){
		printPostOrderBST(node->leftChild);
	}
	if(node->rightChild != nullptr){
		printPostOrderBST(node->rightChild);
	}
	cout << node->word << endl;
}

// Function that takes in a string (the actual word) to find, and an int, and returns the node
BSTNode* BST::searchBST(string toFind, int &opCounter) {
    BSTNode *finder = root;
    while(finder != nullptr) {
        opCounter++;
        if (toFind < finder->word) {
            opCounter++;
            finder = finder->leftChild;
        } else if (toFind > finder->word) {
            finder = finder->rightChild;
            opCounter++;
        }else{
            return finder;
        }
    }

    return finder;
}

// Function that returns the maximum node of the BST (based on the node's value)
string BST::maxBST(BSTNode *node){
	while(node->rightChild != nullptr){
		node = node->rightChild;
	}
	cout << node->word << endl;
	return node->word;
}

// Function that returns the minimum node of the BST (based on the node's value)
string BST::minBST(BSTNode *node){
	while(node->leftChild != nullptr){
		node = node->leftChild;
	}
	cout << node->word << endl;
	return node->word;
}

// Helper function to maxBST(BSTNode *node)
void BST::maxBST(){
	if(!root){
		return; 
	}
	maxBST(root);
}

// Helper function to minBST(BSTNode *node)
void BST::minBST(){
	if(!root){
		return;
	}
	minBST(root);
}