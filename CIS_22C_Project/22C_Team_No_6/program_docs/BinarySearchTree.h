#pragma once
//Binary Search Tree h By Vincent
// Combined BinaryTree and BinarySearchTree.h and .cpp by sriha on 11/22/2020.


//*******************************************************************
//Specification:
//The BinarySearchTree consists of a Binarynode pointer, a count which keep's track of number of
//nodes. The BST inserts a node into BST, removes from it and it helps us to search and print the
//cars. There is even an option of saving to file in BST order which we would not use but is implemented
//***********************************************************************

#include "BinaryNode.h"


class BinarySearchTree
{
public:
    bool insert( Car* item); // insert a node at the correct location
    bool deleteCar( Car* target);    //delete car from tree
    bool search(Car* target, Car* returnedItem[]) const;    // find a target node


    // find the smallest node
    BinaryNode* findSmallest(BinaryNode* nodePtr) const;


    BinarySearchTree() { rootPtr = nullptr; count = 0; }
    //BinarySearchTree(const BinarySearchTree& tree) { }
    virtual ~BinarySearchTree() { destroyTree(rootPtr); }


    //Tranversal wrappers.
    void inOrder(void visit(Car*)) const { _inorder(visit, rootPtr); }
    void printTree(void visit(Car*, int)) const { _printTree(visit, rootPtr, 1); }
    void Savetofile(std::ofstream &file) { _Savetofile(file, this->rootPtr); }


private:
    BinaryNode* rootPtr;		// ptr to root node
    int count;

    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode * _insert(BinaryNode* nodePtr, BinaryNode* newNode);

    // search for target node
    BinaryNode* _search(BinaryNode* nodePtr, Car* target, Car* returnedItem[], int j) const;

    //delete Car
    BinaryNode* _deleteCar(BinaryNode* treePtr, Car* target, BinaryNode* parent);

    // find the smallest node
    BinaryNode* _findSmallest(BinaryNode* nodePtr) const;

    //Save cars to file (This exists now...)
    void _Savetofile(std::ofstream &file, BinaryNode* bnptr);

    // delete all nodes from the tree
    void destroyTree(BinaryNode* nodePtr);

    // internal traverse
    void _inorder(void visit(Car*), BinaryNode* nodePtr) const;
    void _printTree(void visit(Car*, int), BinaryNode* nodePtr, int level) const;
};


