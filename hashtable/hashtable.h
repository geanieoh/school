/*************************************************************
Name: Eugenio Hernandez-Ocampo  
Assignment: Assignment7HashTable  
Purpose: Implement a hash table using separate chaining with  
         linked lists for collision handling.  
***************************************************************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#define HASHTABLESIZE 15

#include <iostream>
#include "linkedlist.h"

class Hashtable{
    public:
        /***********************
        Constructors/Destructors
        ************************/
        Hashtable();
        ~Hashtable();

        /****************
        Getters/Accessors
        ****************/
        bool insertEntry(int, std::string*);
        std::string getData(int);

        /****************
        Setters/Mutators
        ****************/
        bool removeEntry(int);
        int getCount();
        void printTable();
    
    private:
        LinkedList* table[HASHTABLESIZE];
        int count;
        int hash(int);
};

#endif //HASHTABLE_HASHTABLE_H