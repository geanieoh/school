/*********************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Challenge 2
Purpose: Implement and test a Queue ADT for both FIFO and LIFO 
         behavior using a doubly linked list structure and 
         operations such as push, peek, pull, exists, find, and clear.
**********************************************************************/
#include "queue.h"

Queue::Queue(Mode m) : head(nullptr), tail(nullptr), mode(m), itemCount(0) {}

Queue::~Queue(){
    /* ******************************************
    Destructor for the Queue class. Cleans up dynamically allocated
    memory for all nodes in the queue.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    clear();
}

bool Queue::push(int id, const std::string& info){
    /* ******************************************
    Adds a new node to the queue.

    @param (int) id : ID for the new node
    @param (std::string&) info : Information for the new node
    @return (bool) : true if node was added, false if ID is invalid or info is empty
    @exception na : na
    *******************************************/
    bool result;
    if (id <= 0 || info.empty()){
        result = false;
    }
    else{
        Node* newNode = new Node{{id, info}, nullptr, nullptr};

        if(!tail){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        itemCount++;
        result = true;
    }

    return result;
}

bool Queue::pull(Data& out){
    /* ******************************************
    Removes a node from the queue and stores its data in 'out'.

    @param (Data&) out : Reference to store the removed node's data
    @return (bool) : true if node was removed, false if queue is empty
    @exception na : na
    *******************************************/
    bool result;
    if(!head){
        out.id = -1;
        out.information = "";
        result = false;
    }
    else{
        Node* target = (mode == FIFO) ? head : tail;

        out = target->data;

        if(target == head){
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else{
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        }

        delete target;
        itemCount--;
        result = true;
    }

    return result;
}

int Queue::peek(){
    /* ******************************************
    Returns the ID of the node at the front (FIFO) or back (LIFO) of the queue.

    @param na : na
    @return (int) : ID of the node at the front or back of the queue, -1 if empty
    @exception na : na
    *******************************************/
    int result;
    if(!head){
        result = -1;
    }
    else{
        result = (mode == FIFO) ? head->data.id : tail->data.id;
    }

    return result;
}

int Queue::count(){
    /* ******************************************
    Returns the number of nodes in the queue.

    @param na : na
    @return (int) : Number of nodes in the queue
    @exception na : na
    *******************************************/
    return itemCount;
}

void Queue::clear(){
    /* ******************************************
    Clears the queue by deleting all nodes.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    Node* current = head;
    while(current){
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    itemCount = 0;
}

bool Queue::exists(int id){
    /* ******************************************
    Checks if a node with the given ID exists in the queue.

    @param (int) id : ID to check
    @return (bool) : true if node exists, false otherwise
    @exception na : na
    *******************************************/
    bool result = false;
    bool found = false;
    Node* current = head;
    while(current && !found){
        if (current->data.id == id){
            found = true;
            result = true;
        }
        current = current->next;
    }
    return result;
}

int Queue::find(int id){
    /* ******************************************
    Finds the index of a node with the given ID in the queue.

    @param (int) id : ID to find
    @return (int) : Index of the node, -1 if not found
    @exception na : na
    *******************************************/
    int result = -1;
    bool found = false;
    Node* current = (mode == FIFO) ? head : tail;
    int index = 0;

    while(current && !found){
        if(current->data.id == id){
            result = index;
            found = true;
        }
        current = (mode == FIFO) ? current->next : current->prev;
        index++;
    }
    return result;
}