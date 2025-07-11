/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment5Stacks
Purpose: implement a stack data structure that is 
         capable of handling dynamic sizes, ranging 
         from 2 to any number based on a command-line parameter
***************************************************************/

#ifndef STACK_H
#define STACK_H

#include "data.h"

class Stack {

public:
    /***********************
    Constructors/Destructors
    ************************/
    Stack(int*);
    ~Stack();

    /****************
    Getters/Accessors
    *****************/
    bool peek(Data&) const;
    bool isEmpty() const;

    /***************
    Setters/Mutators
    ****************/
    bool push(int, string&);
    bool pop(Data&);

private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H