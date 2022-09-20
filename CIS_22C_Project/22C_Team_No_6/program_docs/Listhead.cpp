//
// Created by riharsha Edukulla on 11/21/2020.
//

#include "Listhead.h"

int Listhead::getNumberofCars() const {
    return numberofCars;
}

void Listhead::setNumberofCars(int number) {
    Listhead::numberofCars = number;
}

BinarySearchTree *Listhead::getBst() const {
    return bst;
}

void Listhead::setBst(BinarySearchTree *b) {
    bst = b;
}

int Listhead::getArrsize() const {
    return arrsize;
}

void Listhead::setArrsize(int arr) {
    arrsize = arr;
}
void Listhead::addcars() {
    numberofCars++;
}
void Listhead::subcars() {
    numberofCars--;
}
Listhead::~Listhead()
{
    delete bst;
    delete hash;
    bst= nullptr;
    delete undodelete;
}

Listhead::Listhead() {
    numberofCars=0;
    bst=new BinarySearchTree();
    hash=new CarTable(arrsize);
    arrsize=0;
    undodelete=new Stack;
}

Listhead::Listhead(int arraysize){
    numberofCars=0;
    bst=new BinarySearchTree();
    hash=new CarTable(arraysize);
    arrsize=arraysize;
    undodelete=new Stack;
}

CarTable *Listhead::getHash() const {
    return hash;
}

void Listhead::setHash(CarTable *hash) {
    Listhead::hash = hash;
}

Stack *Listhead::getUndodelete() const {
    return undodelete;
}

void Listhead::setUndodelete(Stack *undodelete) {
    Listhead::undodelete = undodelete;
}

void Listhead::deletestack() {
    if(undodelete->getLength()>0) {
        for (int i = 0; i <= undodelete->getLength(); i++) {
            Car *temp = undodelete->pop();
        }
    }
}
