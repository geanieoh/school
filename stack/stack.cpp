/*********************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment4SimpleStack
Purpose: understand how to use AI to our
         advantage and to familiarize 
         ourselves with stacks
**********************************/

#include "stack.h"

IntStack::IntStack() : top(-1){}

bool IntStack::isEmpty() const {
    /* ******************************************
    Checks if the stack is empty.

    @param na : na
    @return (bool) : true if empty, false otherwise
    @exceptions na : na
    * *******************************************/
    
    return top == -1;
}

bool IntStack::peek(int &value) const {
    /* ******************************************
    Returns the top value of the stack without popping it.

    @param na : na
    @return (int) : top value
    @exceptions na: na
    * *******************************************/
    
    if (isEmpty()) {
        return false;
    }
    value = stack[top];
    return true;
}

bool IntStack::push(int value) {
    /* ******************************************
    Pushes a value onto the stack.
    
    @param (int) value : value to push
    @return na : na
    @exceptions na : na
    * *******************************************/
    
    if (top >= STACK_SIZE - 1) return false;

    stack[++top] = value;
    return true;
}

bool IntStack::pop(int &value) {
    /* ******************************************
    Pops a value from the stack.

    @param na : na
    @return (int) : popped value
    @exceptions na : na
    * *******************************************/
    
    if (isEmpty()) return false;

    value = stack[top--];
    return true;
}