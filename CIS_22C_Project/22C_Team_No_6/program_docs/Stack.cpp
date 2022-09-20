//
// Created by sriharsha on 12/1/2020.
//

#include "Stack.h"
#include "Car.h"


bool Stack::push(Car *C1) {
    StackNode* newNode; // Pointer to a new node
    // Allocate a new node and store num there.
    newNode = new StackNode;
    if (!newNode)
        return false;

    newNode->undoCars=C1;
    newNode->next = top;
    top = newNode;
    length++;
    return true;
}

Car* Stack::pop() {
    Car *ptr=new Car;
    StackNode* temp = nullptr;
    ptr = top->undoCars;
    temp = top->next;
    delete top;
    top = temp;
    length--;
    return ptr;
}

int Stack::getLength() const {
    return length;
}

void Stack::setLength(int length) {
    Stack::length = length;
}

