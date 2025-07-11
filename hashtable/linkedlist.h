/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Assignment5LinkedList
Purpose: Implement a doubly linked list with operations for 
         adding, deleting, retrieving, and printing nodes.
***************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList{
    public:
        /***********************
        Constructors/Destructors
        ************************/
        LinkedList();
        ~LinkedList();

        /****************
        Getters/Accessors
        *****************/
        bool getNode(int, Data*);
        void printList(bool = false);
        int getCount();
        bool exists(int);

        /***************
        Setters/Mutators
        ****************/
        bool addNode(int, std::string*);
        bool deleteNode(int);
        void clearList();
    
    private:
        Node *head;
};

#endif //LINKEDLIST_H