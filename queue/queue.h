/*********************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Challenge 2
Purpose: Implement and test a Queue ADT for both FIFO and LIFO 
         behavior using a doubly linked list structure and 
         operations such as push, peek, pull, exists, find, and clear.
**********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>

/*
 * Simple data structure that contains
 * an identifier and some kind of data. 
 */
struct Data{
    int id;
    std::string information;
};

class Queue {
public:
    /*********************************************************************
    Enum: Mode
    Purpose: Defines the two modes of the queue - FIFO (first in first out)
             and LIFO (last in first out). Allows the queue to 
             operate in either mode based on the constructor argument.
    *********************************************************************/
    enum Mode {FIFO, LIFO};

    /***********************
    Constructors/Destructors
    ************************/
    Queue(Mode m = FIFO);
    ~Queue();

    /****************
    Getters/Accessors
    *****************/
    int peek();
    bool exists(int);
    int find(int);
    void clear();

    /***************
    Setters/Mutators
    ****************/
    bool push(int, const std::string&);
    bool pull(Data&);
    int count();

private:
    struct Node{
        Data data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    Mode mode;
    int itemCount;

};

#endif //QUEUE_H