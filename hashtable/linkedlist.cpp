/* **********************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: LinkedList Implementation
Purpose: Implement a doubly linked list with operations for 
         adding, deleting, retrieving, and printing nodes.
********************************************************** */

#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList(){
    /* ************************************
    Destructor for the LinkedList class. Cleans up dynamically allocated
    memory for all nodes in the list.

    @param na : na
    @return na : na
    @exception na : na
    * ************************************/ 
    clearList();
}

bool LinkedList::addNode(int id, std::string *str){
    /* ******************************************
    Adds a new node to the linked list in sorted order.
    
    @param (int) id : ID for the new node
    @param (std::string*) str : Pointer to the string data
    @return (bool) : true if node was added, false if ID already exists
    @exception na : na
    * *******************************************/
    bool result = false;

    if (id > 0 && str && !(str->empty())) {
        Node *current = head;
        Node *previous = nullptr;

        while (current && (current->data.id < id)) {
            previous = current;
            current = current->next;
        }

        if (!current || (current->data.id != id)) {
            Node *newNode = new Node{id, std::string(*str), nullptr, nullptr}; // Deep copy

            newNode->next = current;
            newNode->prev = previous;

            if (current) {
                current->prev = newNode;
            }
            if (previous) {
                previous->next = newNode;
            } 
            else {
                head = newNode;
            }

            result = true;
        }
    }

    return result;
}

bool LinkedList::deleteNode(int id){
    /* ******************************************
    Deletes a node from the linked list based on its ID.
    
    @param (int) id : ID of the node to delete
    @return (bool) : true if node was deleted, false if ID not found
    @exception na : na
    * *******************************************/
    
    bool result = false;
    bool found = false;
    Node *current = head;

    while(current && !found){
        if(current->data.id == id){
            if(current->prev) current->prev->next = current->next;
            if(current->next) current->next->prev = current->prev;
            if(current == head) head = current->next;

            delete current;
            result = true;
            found = true;
        }
        current = current->next;
    }
    return result;
}

bool LinkedList::getNode(int id,Data* data){
    /* ******************************************
    Retrieves a node’s data based on its ID.
    
    @param (int) id : ID of the node to retrieve
    @param (Data*) data : Pointer to store retrieved data
    @return (bool) : true if node was found, false otherwise
    @exception na : na
    * *******************************************/
    
    bool result = false;
    bool found = false;
    Node *current = head;
    while(current && !found){
        if(current->data.id == id){
            data->id = current->data.id;
            data->data = current->data.data;
            result = true;
            found = true;
        }
        current = current->next;
    }
    if(!result){
        data->id = -1;
        data->data = "";
    }
    return result;
}

void LinkedList::printList(bool backward){
    /* ******************************************
    Prints the linked list in either forward or backward order.
    
    @param (bool) backward : if true, prints in reverse order
    @return na : na
    @exception na : na
    * *******************************************/
    
    Node *current = head;
    
    if(backward){
        while (current && current->next){
            current = current->next;
        }
    }

    while(current){
        if(current->next != nullptr){
            std::cout << current->data.id << " --> ";
        }
        else{
            std::cout << current->data.id;
        }
        current = backward ? current->prev : current->next;
    }
}

int LinkedList::getCount(){
    /* ******************************************
    Returns the number of nodes in the linked list.
    
    @param na : na
    @return (int) : number of nodes in the list
    @exception na : na
    * *******************************************/
    
    int count = 0;
    Node *current = head;
    while(current){
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::clearList(){
    /* ******************************************
    Clears the linked list by deleting all nodes.
    
    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    
    Node *current = head;
    while(current){
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

bool LinkedList::exists(int id){
    /* ******************************************
    Checks if a node with the given ID exists in the list.
    
    @param (int) id : ID to check
    @return (bool) : true if node exists, false otherwise
    @exception na : na
    * *******************************************/
    
    bool result = false;
    bool found = false;
    Node *current = head;
    while(current && !found){
        if(current->data.id == id){
            result = true;
            found = true;
        }
        current = current->next;
    }
    return result;
}
