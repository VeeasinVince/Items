#pragma once
//Binary Search Tree cpp By Vincent
// Combined BinaryTree and BinarySearchTree.h and .cpp by sriha on 11/22/2020.
//
//*******************************************************************
//Specifications:
//It implements all the methods given in BST.h
//********************************************************************
#include <string>
#include "BinarySearchTree.h"


//////////////////////////////////////////////////////////////////////////////////
///////////////////////// public function definitions ///////////////////////////
////////////////////////////////////////////////////////////////////////////////


//Wrapper for _insert - Inserting items within a tree
bool BinarySearchTree::insert(Car* newEntry)
{
    BinaryNode* newNodePtr = new BinaryNode(newEntry);  //Create space for the new item
    this->rootPtr = _insert(this->rootPtr, newNodePtr); //Calls _insert
    return true;
}


//Wrapper for _deleteCar - Deletes an item within a tree
bool BinarySearchTree::deleteCar(Car* target)
{
    BinaryNode* parent = nullptr;
    if (_deleteCar(this->rootPtr, target, parent))  //If successful delete, return true.
    {
        return true;
    }

    return false;
}



//Wrapper for _search
//Sends in an array as a holder of all copies of a car's secondary key
bool BinarySearchTree::search(Car* anEntry, Car* returnedItem[]) const
{
    _search(this->rootPtr, anEntry, returnedItem, 0);   //Calls _search and collects any cars found
    if (returnedItem[0])    //If atleast one instances has been found
    {
        return true;
    }
    return false;
}




//Finding the smallest, which is the leftmost leaf (wrapper function)
//Used within the code to delete an intenral with two child nodes.
BinaryNode* BinarySearchTree::findSmallest(BinaryNode* nodePtr) const
{
    BinaryNode* temp = nullptr;
    temp = _findSmallest(nodePtr);
    if (temp) // != NULL
        return temp;
    return nullptr;
}



////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// private functions ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



//Implementation of the insert operation
//Will tranverse the tree until an empty space has been found
BinaryNode* BinarySearchTree::_insert(BinaryNode* nodePtr,  BinaryNode* newNodePtr)
{
    BinaryNode* parent = nullptr;
    if (!nodePtr)   //sets up the empty child with the value.
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    parent = nodePtr;
    //Tranverse tree
    if (nodePtr->getItem()->getMaker() > newNodePtr->getItem()->getMaker())         //Value will go to the left
    {
        nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
    }
    else if (nodePtr->getItem()->getMaker() <= newNodePtr->getItem()->getMaker())    //Value will go to the right
    {
        nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
    }

    return nodePtr;
}



//Implementation for the search operation
//Will return nothing if NULL has been reached, array wil remain empty
//Any instance of the specified secondary key within a car in the tree will be added to the array.
BinaryNode* BinarySearchTree::_search(BinaryNode* nodePtr, Car* target, Car* returnedItem[], int j) const
{
    BinaryNode* found = nullptr;
    if (nodePtr == NULL)    //Bottom of the tree reached, leave function
    {
        return found;
    }

    if (nodePtr->getItem()->getMaker() == target->getMaker())   //Found instances will be added to the array.
    {
        returnedItem[j] = nodePtr->getItem();
        j++;

    }
    if (nodePtr->getItem()->getMaker() <= target->getMaker())       //Move right of the tree
    {
        found = _search(nodePtr->getRightPtr(), target, returnedItem, j);
    }
    else if (nodePtr->getItem()->getMaker() > target->getMaker())    //MNove left of the tree
    {
        found = _search(nodePtr->getLeftPtr(), target, returnedItem, j);
    }


    return found;
}



//Implementation of the deleteCar operation
BinaryNode* BinarySearchTree::_deleteCar(BinaryNode* curr, Car* target, BinaryNode* parent)
{
    BinaryNode* found = nullptr;

    if (!curr)  //empty tree
    {
        return nullptr;
    }

    if (target->getMaker() == curr->getItem()->getMaker() &&
        target->getEngineNumber() == curr->getItem()->getEngineNumber()) //Look for secondary key and Primary key for the specified car.
    {//Now determine if leaf, leaf-like, or intenral
        if (curr->isLeaf()) //Leaf
        {
            if (curr == this->rootPtr)    //Only root.
            {
                found = curr;
                curr = NULL;
            }
            else if (parent->getLeftPtr() == curr)  //If removal is on left
            {
                parent->setLeftPtr(nullptr);
                found = parent;
            }
            else                                    //If removal is on right
            {
                parent->setRightPtr(nullptr);
                found = parent;
            }

        }
        else if (curr->getLeftPtr() && !curr->getRightPtr())    //intenal node with left child
        {
            if (!parent)    //Only root.
            {
                this->rootPtr = curr->getLeftPtr();
                found = this->rootPtr;
            }
            else if (parent->getLeftPtr() == curr)  //If removal is on left
            {
                parent->setLeftPtr(curr->getLeftPtr());
                found = curr;
            }
            else                                    //If removal is on right
            {
                parent->setRightPtr(curr->getLeftPtr());
                found = curr;;
            }
        }
        else if (curr->getRightPtr() && !curr->getLeftPtr())    //intenal node with Right child
        {
            if (!parent)    //Only root.
            {
                this->rootPtr = curr->getRightPtr();
                found = this->rootPtr;
            }
            else if (parent->getLeftPtr() == curr)  //If removal is on left
            {
                parent->setLeftPtr(curr->getRightPtr());
                found = curr;
            }
            else                                    //If removal is on right
            {
                parent->setRightPtr(curr->getRightPtr());
                found = curr;
            }
        }
        else //Internal node w/ two childs
        {
            BinaryNode* succ = nullptr;    //to store
            Car* temp;

            succ = findSmallest(curr->getRightPtr());    //Find node from right side which is the smallest
            //Bascially the node right after the target via inorder
            temp = succ->getItem();
            found = _deleteCar(curr->getRightPtr(), succ->getItem(), curr); //Remove old location of the moved pointer
            curr->setItem(temp);                                            //Move pointer to replace the the specified deleted car
        }

    }
    else if (target->getMaker() < curr->getItem()->getMaker())  //Move left
    {
        parent = curr;
        found = _deleteCar(curr->getLeftPtr(), target, parent);
    }
    else if (target->getMaker() >= curr->getItem()->getMaker()) //Move right
    {
        parent = curr;
        found = _deleteCar(curr->getRightPtr(), target, parent);
    }

    return found;

}



//Implementation to find the smallest: recursive
BinaryNode* BinarySearchTree::_findSmallest(BinaryNode* nodePtr) const
{
    BinaryNode* smal = nodePtr;          //Assign current value to smallest.
    if (nodePtr->getLeftPtr() != nullptr)   //As long as something exists to the left.
    {
        nodePtr = nodePtr->getLeftPtr();    //move pointer left
        _findSmallest(nodePtr);   //call it again.
    }


    return smal;
}



void BinarySearchTree::destroyTree(BinaryNode* nodePtr)
{
    if (nodePtr) // != NULL
    {
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}



//Inorder Traversal
void BinarySearchTree::_inorder(void visit(Car*), BinaryNode* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        Car* item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
}



//Prints tree as an indented list
void BinarySearchTree::_printTree(void visit(Car*, int), BinaryNode* nodePtr, int level) const
{
    if (nodePtr) // != NULL
    {
        Car* item = nodePtr->getItem(); //Get value at point
        //Use weird indent tree
        visit(item, level);
        _printTree(visit, nodePtr->getRightPtr(), level + 1);
        _printTree(visit, nodePtr->getLeftPtr(), level + 1);    //Recall function with an added level

    }
}


//saves to file in BST order 
void BinarySearchTree::_Savetofile(std::ofstream &file, BinaryNode* bnptr)
{
    if (bnptr) // != NULL
    {
        Car* item = bnptr->getItem();
        _Savetofile(file, bnptr->getLeftPtr());
        file << item;
        _Savetofile(file, bnptr->getRightPtr());
    }
}