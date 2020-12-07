#ifndef BST_H
#define BST_H

#include <string>

struct BSTNode{
    std::string word;
    int count;
    BSTNode* parent;
    BSTNode* leftChild;
    BSTNode* rightChild;
    
    BSTNode(std::string in_word, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        word = in_word;
        count = 1;
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};


class BST
{
    
public:
    BST();
    void printWord(std::string word);
    void printInOrderBST();
    void printPreOrderBST();
    int addWordNode(std::string word);
    BSTNode* getRoot();
protected:
    
private:
    void printBST(BSTNode * node);
    void printInOrderBST(BSTNode * node);
    void printPreOrderBST(BSTNode * node);
    BSTNode* searchBST(std::string word, int &opCounter); //use this function to find pointer to node in BST        
    BSTNode* root;
};

#endif // BST_H
