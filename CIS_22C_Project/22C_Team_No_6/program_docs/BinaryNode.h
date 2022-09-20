#pragma once
//Binary Node h By Vincent
//***************************************************************
//The binary node contains all the nodes of BST
//The private members include a car item which is the data of the node
//It also contains leftpointer and the right pointer
//In public it has constructors, setter and getters
//******************************************************************


#ifndef _BINARY_NODE
#define _BINARY_NODE
#include "Car.h"

class BinaryNode
{
private:
    Car* item;         // Pointer to actual Car data
    BinaryNode* leftPtr;		// Pointer to left
    BinaryNode* rightPtr;		// Pointer to right

public:
    // const constructors
    BinaryNode(Car* anItem) { item = anItem; leftPtr = 0; rightPtr = 0; }
    BinaryNode(Car* anItem, BinaryNode* left, BinaryNode* right)
    {
        item = anItem;  leftPtr = left;  rightPtr = right;
    }

    // setters
    void setItem(Car* anItem) { item = anItem; }
    void setLeftPtr(BinaryNode* lefCar) { leftPtr = lefCar; }
    void setRightPtr(BinaryNode* righCar) { rightPtr = righCar; }

    // getters
    Car* getItem() const { return item; }
    BinaryNode* getLeftPtr() const { return leftPtr; }
    BinaryNode* getRightPtr() const { return rightPtr; }

    // other functions
    bool isLeaf() const { return (leftPtr == 0 && rightPtr == 0); }

};

#endif
