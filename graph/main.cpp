/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Final Project
Purpose: Implement a graph data structure with vertices and 
         edges and operations like adding/removing 
         vertices and edges, and traversals. Can contain up to
         1000 vertices.
***************************************************************/

#include "main.h"

int main(int argc, char** argv){
    /* ***************************************************************
    Main function to test the graph implementation.
  
    @param (int) (char) : n umber of command-line arguments and string
    @return (int) : exit status 
    @exceptio na : na
    * ****************************************************************/
    srand(time(NULL));
    int graphSize = (rand() % MAX_TEST_DATA) + MIN_TEST_DATA;

    Graph graph;

    //testing all methods on empty graph
    cout << "=== Testing on Empty Graph ===" << endl;
    cout << "checking if graph is empty... ";
    if(graph.isEmpty()){
        cout << "empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }
    cout << endl;

    cout << "graph has " << graph.getVertexCount() << " vertices" << endl;
    graph.getVertex(BASE_ID);
     if(graph.removeVertex(BASE_ID)){
        cout << "successfully removed vertex " << BASE_ID << endl;
    }
    else{
        cout << "failed removing vertex " << BASE_ID << endl;
    }
    cout << endl;

    cout << "graph has " << graph.getEdgeCount() << " edges" << endl;
    if(graph.edgeExists(BASE_ID, BASE_ID + 1)){
        cout << "edge from " << BASE_ID << " to " << BASE_ID + 1 << " exists" << endl;
    }
    else{
        cout << "edge from " << BASE_ID << " to " << BASE_ID + 1 << " does not exists" << endl;
    }
    if(graph.removeEdge(BASE_ID, BASE_ID + 1)){
        cout << "successfully removed edge from vertex " << BASE_ID << " to " << BASE_ID + 1 << endl;
        }
    else{
        cout << "failed removing edge from vertex " << BASE_ID << " to " << BASE_ID + 1 << endl;
    }
    cout << endl;

    cout << "testing breadth first traversal... ";
    graph.breadthFirst(BASE_ID);
    cout << "testing depth first traversal... ";
    graph.depthFirst(BASE_ID);
    cout << endl;
    
    graph.displayGraph();

    //testing addVertex method
    cout << "=== Testing Adding Vertices ===" << endl;
    cout << "adding " << graphSize << " vertices..." << endl;
    for(int i = 0; i < graphSize; i++){
        Data* tmpData = new Data;
        tmpData->val = (rand() % MAX_NUM_VALUE) + 1;
        if(tmpData->val%2){
            tmpData->information = "odd";
        }
        else{
            tmpData->information = "even";
        }
        if(graph.addVertex(i, tmpData)){
            cout << "successfully added vertex " << i << endl;
            cout << "\tvalue: " << tmpData->val << "\tinfo: " << tmpData->information << endl;
        }
        else{
            cout << "failed adding vertex " << i << endl;
        }
    }
    cout << "graph has " << graph.getVertexCount() << " vertices\n" << endl;
    graph.displayGraph();

    //testing getVertex method
    cout << "=== Testing Vertex Retrieval ===" << endl;
    for(int i = 1; i < graph.getVertexCount() + 1; i++){
        graph.getVertex(i);
    }
    cout << "\n" << endl;

    //testing addEdge method
    cout << "=== Testing Adding Edges ===" << endl;
    int edgeAttemps = graphSize*EDGE_ATTEMPTS_MULTIPLIER;
    for(int i = 1; i < edgeAttemps; i++){
        int from = (rand() % graphSize) + 1;
        int to = (rand() % graphSize) + 1;
        if(graph.addEdge(from, to)){
            cout << "successfully added edge from " << from << " to " << to << endl;
        } 
        else{
            cout << "failed adding edge from " << from << " to " << to << endl;
        }
    }
    cout << "graph has " << graph.getEdgeCount() << " edges\n" << endl;
    graph.displayGraph();

    //testing removeVertex method
    cout << "=== Testing Vertex Removal ===" << endl;
    for(int i = 0; i < graph.getVertexCount()/VERTEX_REMOVAL_DIVISOR; i++){
        int num = (rand()%graphSize) + 1;
        if(num == BASE_ID){
            num += 1;
        }
        if(graph.removeVertex(num)){
            cout << "successfully removed vertex " << num << endl;
        }
        else{
            cout << "failed removing vertex " << num << endl;
        }
    }
    cout << "graph has " << graph.getVertexCount() << " vertices" << endl;
    cout << "graph has " << graph.getEdgeCount() << " edges\n" << endl;
    graph.displayGraph();

    //testing removeEdge method
    cout << "=== Testing Edge Removal ===" << endl;
    for(int i = 0; i < edgeAttemps; i++){
        int from = (rand()%graphSize) + 1;
        int to = (rand()%graphSize) + 1;
        if(graph.removeEdge(from, to)){
            cout << "successfully removed edge from vertex " << from << " to " << to << endl;
        }
        else{
            cout << "failed removing edge from vertex " << from << " to " << to << endl;
        }
    }
    cout << "graph has " << graph.getVertexCount() << " vertices" << endl;
    cout << "graph has " << graph.getEdgeCount() << " edges\n" << endl;
    graph.displayGraph();

    //testing edgeExists method
    cout << "=== Testing edgeExists Method ===" << endl;
    for(int i = 0; i < edgeAttemps; i++){
        int from = (rand()%graphSize) + 1;
        int to = (rand()%graphSize) + 1;
        if(graph.edgeExists(from, to)){
            cout << "edge from vertex " << from << " to " << to << " exists" << endl;
        }
        else{
            cout << "edge from vertex " << from << " to " << to << " does not exist" << endl;
        }
    }
    cout << endl;

    //testing breadthFirst method
    cout << "=== Testing Breadth First Traversal ===" << endl;
    graph.breadthFirst(BASE_ID);
    cout << endl;

    //testing depthFirst method
    cout << "=== Testing Depth First Traversal ===" << endl;
    graph.depthFirst(BASE_ID);
    cout << endl;

    return 0;
}