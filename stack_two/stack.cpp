/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment5Stacks
Purpose: implement a stack data structure that is 
         capable of handling dynamic sizes, ranging 
         from 2 to any number based on a command-line parameter
***************************************************************/

#include "stack.h"

Stack::Stack(int *paramPassed){
    /* ************************************
    Constructor for the Stack class. Initializes the stack size and 
    allocates memory for the stack array based on the parameter passed.

    @param paramPassed : pointer to the stack size
    @return na : na
    @exception na : na
    * ************************************/

    size = (*paramPassed >= 2) ? *paramPassed : 10;
    *paramPassed = size;
    stack = new Data*[size];
    top = -1;
}

Stack::~Stack(){
    /* ************************************
    Destructor for the Stack class. Cleans up the dynamically allocated 
    memory for each element in the stack and for the stack array itself.

    @param na : na
    @return na : na
    @exception na : na
    * ************************************/

    for(int i = 0; i <= top; i++){
        delete stack[i];
    }
    delete[] stack;
}

bool Stack::isEmpty() const {
    /* ******************************************
    Checks if the stack is empty.

    @param na : na
    @return (bool) : true if empty, false otherwise
    @exceptions na : na
    * *******************************************/
    
    return top == -1;
}

bool Stack::peek(Data &value) const {
    /* ******************************************
    Returns the top value of the stack without popping it.

    @param na : na
    @return (int) : top value
    @exceptions std::out_of_range : if stack is empty
    * *******************************************/
    bool result = true;

    if (isEmpty()) {
        result = false;
    }
    else{
        value = *stack[top];
    }

    return result;
}

bool Stack::push(int id, std::string& info) {
    /* ******************************************
    Pushes a value onto the stack.
    
    @param (Data) value : value to push
    @return na : na
    @exceptions na : na
    * *******************************************/

    bool result = true;

    if(top >= size - 1 || id < 0 || info.empty()){
        result = false;
    }
    else{
        stack[++top] = new Data;
        stack[top]->id = id;
        stack[top]->information = info;
    }

    return result;
}

bool Stack::pop(Data &data) {
    /* ******************************************
    Pops a value from the stack.

    @param na : na
    @return (int) : popped value
    @exceptions std::out_of_range : if stack is empty
    * *******************************************/
    
    bool result = true;

    if (isEmpty()) {
        result = false;
    }
    else{
        data = *stack[top];
        delete stack[top];
        stack[top] = nullptr;
        top--;
    }

    return result;
}