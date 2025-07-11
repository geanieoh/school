/*********************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment4SimpleStack
Purpose: understand how to use AI to our
         advantage and to familiarize 
         ourselves with stacks
**********************************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define STACK_SIZE 10

class IntStack {
public:
    /***********************
    Constructors/Destructors
    ************************/
    IntStack();

    /****************
    Getters/Accessors
    *****************/
    bool peek(int&) const;
    bool isEmpty() const;

    /***************
    Setters/Mutators
    ****************/
    bool push(int);
    bool pop(int&);

private:
    int stack[STACK_SIZE];
    int top;
};

#endif // STACK_STACK_H