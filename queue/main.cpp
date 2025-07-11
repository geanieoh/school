/*********************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Challenge 2
Purpose: Implement and test a Queue ADT for both FIFO and LIFO 
         behavior using a doubly linked list structure and 
         operations such as push, peek, pull, exists, find, and clear.
**********************************************************************/
#include "main.h"

int main(int argc, char** argv){
    /* ***************************************************************
    Main function to test the queue implementation.
  
    @param (int) (char) : n umber of command-line arguments and string
    @return (int) : exit status 
    @exceptio na : na
    * ****************************************************************/
    srand(time(NULL));
    int queueSize = (rand() % MAX_TEST_DATA) + 1;
    Data tmpData;
    Queue qFIFO(Queue::FIFO);
    Queue qLIFO(Queue::LIFO);

    /*TESTING FIFO QUEUE*/
    cout << "=== TESTING FIFO ===\n" << endl;

    //testing push
    cout << "Testing Push" << endl;
    for(int i = 0; i < queueSize; i++){
        tmpData.id = rand() % MAX_ID_VALUE;
        if(!(tmpData.id%2)){
            tmpData.information = "even";
        }
        else{
            tmpData.information = "odd";
        }
        cout << "adding data: {" << tmpData.id << ", " << tmpData.information <<  "}... ";
        if(qFIFO.push(tmpData.id, tmpData.information)){
            cout << "successfully added data" << endl;
        }
        else{
            cout << "failed to add data" << endl;
        }
    }
    cout << "checking queue: " << qFIFO.count() << " items\n" << endl;

    //testing peek and pull
    cout << "Testing Peek and Pull" << endl;
    for(int i = 0; i < queueSize/2; i++){
        cout << "next ID to pull: " << qFIFO.peek();
        if(qFIFO.pull(tmpData)){
            cout << ", pulled: {" << tmpData.id << ", " << tmpData.information << "}" << endl;
        }
        else{
            cout << ", failed to pull data" << endl;
        }
    }
    cout << endl;

    //testing exists
    cout << "Testing Exists" << endl;
    int id;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        cout << "looking for ID " << id << "...";
        if(qFIFO.exists(id)){
            cout << " found." << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing find
    cout << "Testing Find" << endl;
    int index;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        index = qFIFO.find(id);
        cout << "looking for ID " << id << "...";
        if(index != -1){
            cout << " found at index " << index << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing on cleared queue
    cout << "clearing queue...";
    qFIFO.clear();
    
    cout << " checking queue: " << qFIFO.count() << " items\n" << endl;

    //testing peek and pull
    cout << "Testing Peek and Pull on CLEARED queue" << endl;
    for(int i = 0; i < queueSize/2; i++){
        cout << "next ID to pull: " << qFIFO.peek();
        if(qFIFO.pull(tmpData)){
            cout << ", pulled: {" << tmpData.id << ", " << tmpData.information << "}" << endl;
        }
        else{
            cout << ", failed to pull data" << endl;
        }
    }
    cout << endl;

    //testing exists
    cout << "Testing Exists on CLEARED queue" << endl;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        cout << "looking for ID " << id << "...";
        if(qFIFO.exists(id)){
            cout << " found." << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing find
    cout << "Testing Find on CLEARED queue" << endl;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        index = qFIFO.find(id);
        cout << "looking for ID " << id << "...";
        if(index != -1){
            cout << " found at index " << index << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    /*TESTING LIFO QUEUE*/
    cout << "=== TESTING LIFO ===\n" << endl;

    //testing push
    cout << "Testing Push" << endl;
    for(int i = 0; i < queueSize; i++){
        tmpData.id = rand() % MAX_ID_VALUE;
        if(!(tmpData.id%2)){
            tmpData.information = "even";
        }
        else{
            tmpData.information = "odd";
        }
        cout << "adding data: {" << tmpData.id << ", " << tmpData.information <<  "}... ";
        if(qLIFO.push(tmpData.id, tmpData.information)){
            cout << "successfully added data" << endl;
        }
        else{
            cout << "failed to add data" << endl;
        }
    }
    cout << "checking queue: " << qLIFO.count() << " items\n" << endl;

    //testing peek and pull
    cout << "Testing Peek and Pull" << endl;
    for(int i = 0; i < queueSize/2; i++){
        cout << "next ID to pull: " << qLIFO.peek();
        if(qLIFO.pull(tmpData)){
            cout << ", pulled: {" << tmpData.id << ", " << tmpData.information << "}" << endl;
        }
        else{
            cout << ", failed to pull data" << endl;
        }
    }
    cout << endl;

    //testing exists
    cout << "Testing Exists" << endl;
    id;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        cout << "looking for ID " << id << "...";
        if(qLIFO.exists(id)){
            cout << " found." << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing find
    cout << "Testing Find" << endl;
    index;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        index = qLIFO.find(id);
        cout << "looking for ID " << id << "...";
        if(index != -1){
            cout << " found at index " << index << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing on cleared queue
    cout << "clearing queue...";
    qLIFO.clear();

    cout << " checking queue: " << qLIFO.count() << " items\n" << endl;

    //testing peek and pull
    cout << "Testing Peek and Pull on CLEARED queue" << endl;
    for(int i = 0; i < queueSize/2; i++){
        cout << "next ID to pull: " << qLIFO.peek();
        if(qLIFO.pull(tmpData)){
            cout << ", pulled: {" << tmpData.id << ", " << tmpData.information << "}" << endl;
        }
        else{
            cout << ", failed to pull data" << endl;
        }
    }
    cout << endl;

    //testing exists
    cout << "Testing Exists on CLEARED queue" << endl;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        cout << "looking for ID " << id << "...";
        if(qLIFO.exists(id)){
            cout << " found." << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    //testing find
    cout << "Testing Find on CLEARED queue" << endl;
    for(int i = 0; i < queueSize; i++){
        id = (rand() % MAX_ID_VALUE) + 1;
        index = qLIFO.find(id);
        cout << "looking for ID " << id << "...";
        if(index != -1){
            cout << " found at index " << index << endl;
        }
        else{
            cout << " not found." << endl;
        }
    }
    cout << endl;

    return 0;
}