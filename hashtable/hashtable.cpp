/* *************************************************************
Name: Eugenio Hernandez-Ocampo  
Assignment: Assignment7HashTable  
Purpose: Implement a hash table using separate chaining with  
         linked lists for collision handling.  
************************************************************** */

#include "hashtable.h"

Hashtable::Hashtable() {
    /* ******************************************
    Constructor for the Hashtable class. Initializes the hash table size
    and sets all entries to nullptr.

    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; ++i) {
        table[i] = nullptr;
    }
}

Hashtable::~Hashtable() {
    /* ******************************************
    Destructor for the Hashtable class. Deletes any dynamically allocated
    linked lists in the table.

    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    for (int i = 0; i < HASHTABLESIZE; ++i) {
        if (table[i]) {
            delete table[i];
        }
    }
}

int Hashtable::hash(int key) {
    /* ******************************************
    Hash function that calculates the index for a given key using the
    modulo operation.

    @param (int) key : The key to hash
    @return (int) : The index calculated by key % HASHTABLESIZE
    @exception na : na
    * *******************************************/
    return key % HASHTABLESIZE;
}

bool Hashtable::insertEntry(int id, std::string* data) {
    /* ******************************************
    Inserts a new entry into the hash table, using separate chaining
    for collision handling.

    @param (int) id : The ID to insert into the hash table
    @param (std::string*) data : Pointer to the data associated with the ID
    @return (bool) : true if the entry was inserted successfully, false otherwise
    @exception na : na
    * *******************************************/
    int index = hash(id);

    if (!table[index]) {
        table[index] = new LinkedList();
    }

    bool result = table[index]->addNode(id, data);

    if (result) {
        count++;
    }

    return result;
}

std::string Hashtable::getData(int id) {
    /* ******************************************
    Retrieves the data associated with a specific entry in the hash table.

    @param (int) id : The ID to retrieve the data for
    @return (std::string) : The data associated with the ID, or "Data not found" if not present
    @exception na : na
    * *******************************************/
    std::string string = "Data not found";

    int index = hash(id);
    Data data;
    
    if (index >= 0 && table[index] && table[index]->getNode(id, &data)) {
        string = data.data;
    }

    return string;
}

bool Hashtable::removeEntry(int id) {
    /* ******************************************
    Removes an entry from the hash table by deleting the corresponding
    node in the linked list.

    @param (int) id : The ID of the entry to remove
    @return (bool) : true if the entry was successfully removed, false otherwise
    @exception na : na
    * *******************************************/
    bool result = false;

    int index = hash(id);

    if (index >= 0 && table[index]) {
        if (table[index]->deleteNode(id)) {
            count--;

            if (table[index]->getCount() == 0) {
                delete table[index];
                table[index] = nullptr;
            }

            result = true;
        }
    }

    return result;
}

int Hashtable::getCount() {
    /* ******************************************
    Returns the total number of entries in the hash table.

    @param na : na
    @return (int) : The number of entries in the hash table
    @exception na : na
    * *******************************************/
    return count;
}

void Hashtable::printTable() {
    /* ******************************************
    Prints the hash table, showing each index and its associated linked list 
    or "Empty" if no entry exists.

    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    for (int i = 0; i < HASHTABLESIZE; ++i) {
        std::cout << "Entry " << i << ": ";
        if (table[i]) {
            table[i]->printList();
        } 
        else {
            std::cout << "Empty";
        }
        std::cout << std::endl;
    }
}
