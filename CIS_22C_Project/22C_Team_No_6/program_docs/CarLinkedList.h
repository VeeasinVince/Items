//Created by Khush Naidu

/* ==============================================================================================
                                    <DESCRIPTION>

The class "CarLinkedList" is where functions that handle the linked lists which are resultants of collision during insertion in the hash table. This includes insertNode, searchNode, deleteNode as well as save to file.
CarLinkedList.h is the header file where the constructor as well as function definitions are declared.
=================================================================================================
*/

#pragma once
#include "Car.h"
class CarLinkedList
{
private:
    Car* data;
    CarLinkedList* next;
    int count;           // To keep track of the number of nodes in the list

public:
    CarLinkedList(){
        data = nullptr;
        count = 0;
        next = nullptr;
    }

    // Linked list operations
    void insertNode(Car* dataIn,CarLinkedList* &itemIn);
    bool searchNode(string target, Car*& dataOut,CarLinkedList* searchItem);
    bool deleteNode(string target, Car*&dataOut, CarLinkedList *&deleteItem);
    void Savehashtofile(std::ofstream &fin,CarLinkedList* travel);
    void collisionrehash(CarLinkedList* &travel,CarLinkedList* old  );

};
