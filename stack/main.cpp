/*********************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment4SimpleStack
Purpose: understand how to use AI to our
         advantage and to familiarize 
         ourselves with stacks
**********************************/

#include "main.h"

int main() {
    /* **********************************************************
    Creates an IntStack object and tests each method of the stack
    (peek(), push(), pop(), and peek())

    param na : na
    return (int) : error code
    exceptions na : na
    * ***********************************************************/

    IntStack myStack;
    int value;

    //UNDERFLOW
    std::cout << "\n*UNDERFLOW*\n" << std::endl;

    if(myStack.isEmpty()) std::cout << "STACK IS EMPTY" << std::endl;
    else std::cout << "STACK IS NOT EMPTY" << std::endl;

    value = rand() % 100;

    if(myStack.pop(value)) std::cout << "Popped: " << value << std::endl;
    else std::cout << "Stack is empty, cannot pop" << std::endl;

    if(myStack.peek(value)) std::cout << "Peeking... value: " << value << std::endl;
    else std::cout << "Stack is empty, cannot peek" << std::endl;

    if(!myStack.push(value)) std::cout << "Stack is full, cannot push" << std::endl;
    else std::cout << "Pushed value " << value << std::endl;

    //NEITHER
    std::cout << "\n*NEITHER*\n" << std::endl;

    if(myStack.isEmpty()) std::cout << "STACK IS EMPTY" << std::endl;
    else std::cout << "STACK IS NOT EMPTY" << std::endl;

    if(myStack.peek(value)) std::cout << "Peeking... value: " << value << std::endl;
    else std::cout << "Stack is empty, cannot peek" << std::endl;

    if(myStack.pop(value)) std::cout << "Popped: " << value << std::endl;
    else std::cout << "Stack is empty, cannot pop" << std::endl;

    if(!myStack.push(value)) std::cout << "Stack is full, cannot push" << std::endl;
    else std::cout << "Pushed value " << value << std::endl;

    //OVERFLOW
    std::cout << "\n*OVERFLOW*\n" << std::endl;

    for(int i = 0; i < STACK_SIZE; i++){
        value = rand() % 100;
        myStack.push(value);
    }

    if(myStack.isEmpty()) std::cout << "STACK IS EMPTY" << std::endl;
    else std::cout << "STACK IS NOT EMPTY" << std::endl;

    if(!myStack.push(value)) std::cout << "Stack is full, cannot push" << std::endl;
    else std::cout << "Pushed value " << value << std::endl;

    if(myStack.peek(value)) std::cout << "Peeking... value: " << value << std::endl;
    else std::cout << "Stack is empty, cannot peek" << std::endl;

    if(myStack.pop(value)) std::cout << "Popped: " << value << std::endl;
    else std::cout << "Stack is empty, cannot pop" << std::endl;

    //RANDOM OPERATIONS
    std::cout << "\n*RANDOM OPERATIONS*\n" << std::endl;

    for(int i = 0; i < STACK_SIZE * 100; i++){
        int operation = rand() % 4;
        value = rand() % 100;

        switch(operation){
            case 0: 
                if(myStack.isEmpty()) std::cout << "STACK IS EMPTY" << std::endl;
                else std::cout << "STACK IS NOT EMPTY" << std::endl;
                break;
            case 1:
                if(myStack.peek(value)) std::cout << "Peeking... value: " << value << std::endl;
                else std::cout << "Stack is empty, cannot peek" << std::endl; 
                break;
            case 2:
                if(!myStack.push(value)) std::cout << "Stack is full, cannot push" << std::endl;
                else std::cout << "Pushed value " << value << std::endl;
                break; 
            case 3:
                if(myStack.pop(value)) std::cout << "Popped: " << value << std::endl;
                else std::cout << "Stack is empty, cannot pop" << std::endl;
                break;
        }
    }
    
    return 0;
}