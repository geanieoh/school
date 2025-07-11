/*************************************************************
Name: Eugenio Hernandez-Ocampo  
Assignment: Assignment7HashTable  
Purpose: Implement a hash table using separate chaining with  
         linked lists for collision handling.  
***************************************************************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable table;

    // Show it is empty by calling getCount and printTable
    std::cout << "Initial Table State:" << std::endl;
    std::cout << "Table count: " << table.getCount() << std::endl;
    table.printTable();
    std::cout << std::endl;

    // Try and put ALL the test data into the table and show what happens
    std::cout << "Inserting test data..." << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        table.insertEntry(ids[i], &strs[i]);
    }

    // Show the table after inserting the data
    std::cout << "\nTable State after Insertion:" << std::endl;
    std::cout << "Table count: " << table.getCount() << std::endl;
    table.printTable();
    std::cout << std::endl;

    // Insert duplicate data (should not insert) and show the result
    table.insertEntry(ids[testdatasize - 2], &strs[testdatasize - 2]);

    // Insert bad data (should not insert) and show the result
    table.insertEntry(ids[testdatasize - 1], &strs[testdatasize - 1]);

    std::cout << "\nTable State after trying to insert duplicate and bad data:" << std::endl;
    std::cout << "Table count: " << table.getCount() << std::endl;
    table.printTable();
    std::cout << std::endl;

    // Retrieve data for a valid ID
    for(int i = 0; i < table.getCount(); i++){
        std::cout << "Retrieving data for valid ID (Example ID: " << ids[i] << "):" << std::endl;
        std::string data = table.getData(ids[i]);
        std::cout << "Data: " << data << std::endl;
        std::cout << std::endl;
    }

    // Retrieve data for an invalid ID (known bad ID)
    std::cout << "Retrieving data for invalid ID (known bad ID -1):" << std::endl;
    std::string data = table.getData(ids[testdatasize - 1]);
    std::cout << "Data: " << data << std::endl;
    std::cout << std::endl;

    // Remove an entry and show the updated table state
    for(int i = 0; i < testdatasize/2; i++){
        std::cout << "Removing entry with ID: " << ids[i] << std::endl;
        table.removeEntry(ids[i]);
    }
    std::cout << "\nTable State after Removal:" << std::endl;
    std::cout << "Table count: " << table.getCount() << std::endl;
    table.printTable();
    std::cout << std::endl;

    // Show final state
    std::cout << "\nFinal Table State:" << std::endl;
    std::cout << "Table count: " << table.getCount() << std::endl;
    table.printTable();

    return 0;
}
