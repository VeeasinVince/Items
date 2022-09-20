//
// Created by sriharsha on 12/1/2020.
//
//=======================================================
//              <Description>
//This is a stack and we use it for undo delete operations.
//this includes pop,push
//======================================================

#ifndef CIS22CFINALPROJECT_STACK_H
#define CIS22CFINALPROJECT_STACK_H

#include<iostream>
#include "Car.h"


struct StackNode {
    Car *undoCars;           // Value in the node
    StackNode* next;     // Pointer to next node
};


class Stack
{
private:
    StackNode* top;          // Pointer to the stack top
    int length;

public:
    Stack(){
        top=nullptr;
        length=0;
    }

    int getLength() const;
    void setLength(int length);
    bool push(Car *C1);
    Car* pop();
};















#endif //CIS22CFINALPROJECT_STACK_H
