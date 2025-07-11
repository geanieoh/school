/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment5Stacks
Purpose: implement a stack data structure that is 
         capable of handling dynamic sizes, ranging 
         from 2 to any number based on a command-line parameter
***************************************************************/

#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}

bool check_if_num(std::string string){
    /* ************************************
    Checks if a given string consists only 
    of numeric digits, allowing a leading 
    '-' for negative numbers.

    @param string : input string to check
    @return bool : true if the string is a valid number, false otherwise
    @exception na : na
    * ************************************/

    int i = 0;
    bool result = true;

    if(string[0] == '-' && string[1] != '\0'){
        i++;
    }

    while(string[i] != '\0'){
        if(!isdigit(string[i])){
            result = false;
        }
        i++;
    }

    return result;
}