//Created by Khush Naidu

/* ==============================================================================================
                                    <DESCRIPTION>

CarLinkedList.cpp is where the linked lists are created and functions such as insertNode, searchNode, deleteNode and save to file are implemented.
=================================================================================================
*/


#include "CarTable.h"
#include "CarLinkedList.h"
#include <iostream>         // For cout  and NULL
using namespace std;

//=====================================================
//               INSERT NODE FUNCTION
//=====================================================

void CarLinkedList::insertNode(Car* dataIn,CarLinkedList* &itemIn)
{
    CarLinkedList *newNode;  // A new node
    CarLinkedList *currptr;     // To traverse the list
    CarLinkedList *prevptr;     // The previous node
    currptr = itemIn;
    newNode = new CarLinkedList; //creared new linked list
    newNode->data = dataIn;
    prevptr = nullptr;
    while(currptr != nullptr) //insert and move to next if item is not null
    {
        prevptr = currptr;
        currptr = currptr->next;
    }
    if(prevptr == nullptr) //in the event item is first in linked list
    {
        itemIn = newNode;
        newNode->next = currptr;
    }
    else
    {
        prevptr->next = newNode;
        newNode->next = currptr;
    }
}

//=====================================================
//               SEARCH NODE FUNCTION
//=====================================================

bool CarLinkedList::searchNode(string target, Car*& dataOut,CarLinkedList* searchItem)
{
    CarLinkedList* currptr;
    currptr = searchItem;
    while(currptr != nullptr)
    {
        if(currptr->data->getEngineNumber() == target) //check if target matches element in linked list
        {
            dataOut = currptr->data; //store car data after being found
            return true;
        }
        currptr = currptr->next;
    }
    return false;
}

//=====================================================
//               DELETE NODE FUNCTION
//=====================================================

bool CarLinkedList::deleteNode(string target, Car *&dataOut, CarLinkedList *&deleteItem)
{
    CarLinkedList *currptr;       // To traverse the list
    CarLinkedList *prevptr;        // To point to the previous node

    currptr = deleteItem;
    prevptr = nullptr;
    if(currptr->data->getEngineNumber() == target)
    {
        deleteItem = deleteItem->next;
        delete currptr;
        return true;
    }
    else
    {
        prevptr = currptr;
        currptr = currptr->next;
        while(currptr)
        {
            if(currptr->data->getEngineNumber() == target)
            {
                prevptr->next = currptr->next;
                delete currptr;
                return true;
            }
            prevptr = currptr;
            currptr = currptr->next;
        }
    }
    return false;
}

//================================================================
//                  SAVE TO FILE FUNCTION
//================================================================

void CarLinkedList::Savehashtofile(std::ofstream &fin, CarLinkedList *travel)
{
    CarLinkedList* currptr;
    currptr = travel;

    while(currptr)
    {
        fin<<currptr->data;
        currptr=currptr->next;
    }
}

//================================================
//          rehash
//================================================

void CarLinkedList::collisionrehash(CarLinkedList*& travel,CarLinkedList* old ){
    CarLinkedList* currptr;
    currptr = old;
    CarLinkedList *pastptr;
    pastptr=old;

int i=0;
    while(pastptr)
    {
        currptr->data=pastptr->data;
        currptr=currptr->next;
        pastptr=pastptr->next;
    }
}