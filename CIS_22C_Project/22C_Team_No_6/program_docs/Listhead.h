/*
// Created by Sriharsha Edukulla on 11/21/2020.
 This has our pointer to bst,stack and hash. We use this as it makes it easy for us to move around main
 */
#pragma once
#include <iostream>
#include "BinarySearchTree.h"
#include "CarTable.h"
#include "Stack.h"
class Listhead {
private:
    int numberofCars;
    BinarySearchTree *bst;
    int arrsize;
    CarTable *hash;
    Stack *undodelete;
public:
    Listhead();
    Listhead(int arraysize);
    ~Listhead();
    int getNumberofCars() const;
    void setNumberofCars(int numberofCars);
    BinarySearchTree *getBst() const;
    void setBst(BinarySearchTree *bst);
    int getArrsize() const;
    void setArrsize(int arrsize);
    void addcars();
    void subcars();
    CarTable *getHash() const;
    void setHash(CarTable *hash);
    void deletestack();
    Stack *getUndodelete() const;
    void setUndodelete(Stack *undodelete);


};


