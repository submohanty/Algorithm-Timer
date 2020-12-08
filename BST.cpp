#include "BST.h"
#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;

BST::BST() {
    root = nullptr;
}

BSTNode* BST::getRoot(){
    return root;
}
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

void BST::printInOrderBST() {
    if (!root) {
        return;
    }
    printInOrderBST(root);
}

void BST::printInOrderBST(BSTNode *node) {
    if (!node) {
        return;
    }
    
    printInOrderBST(node->leftChild);   
    cout << node->word<<endl;
    printInOrderBST(node->rightChild);
}

void BST::printPreOrderBST() {
    if (!root) {
        return;
    }
    printPreOrderBST(root);
}

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

void BST::printPostOrderBST(){
	if(!root){
		return;
	}
	printPostOrderBST(root);
}

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

string BST::maxBST(BSTNode *node){
	while(node->rightChild != nullptr){
		node = node->rightChild;
	}
	cout << node->word << endl;
	return node->word;
}

string BST::minBST(BSTNode *node){
	while(node->leftChild != nullptr){
		node = node->leftChild;
	}
	cout << node->word << endl;
	return node->word;
}

void BST::maxBST(){
	if(!root){
		return; 
	}
	maxBST(root);
}

void BST::minBST(){
	if(!root){
		return;
	}
	minBST(root);
}