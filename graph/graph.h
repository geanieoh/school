/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Final Project
Purpose: Implement a graph data structure with vertices and 
         edges and operations like adding/removing 
         vertices and edges, and traversals. Can contain up to
         1000 vertices.
***************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>

// Maximum number of vertices allowed in the graph
#define MAX_VERTICES 1000

/***********************
Data struct for vertex
***********************/
struct Data{
    int val;
    std::string information;
};

class Graph{
    private:
        struct Edge;

        /*******************
        Vertex node struct
        *******************/
        struct Vertex{
            int id;
            Data* data;
            Edge* adjacencyList;
            Vertex* next;
        };

        /*******************
        Edge node struct
        *******************/
        struct Edge{
            Vertex* destination;
            Edge* next;
        };

        Vertex* head;
        int vertexCount;
        int edgeCount;

        /***********************
        Helper functions
        ***********************/
        Vertex* findVertex(int);
        bool edgeExists(Vertex*, Vertex*);
        void removeAllEdgesTo(Vertex*);

    public:
        /*******************
        Constructors/Destructors
        *******************/
        Graph();
        ~Graph();

        /***********************
        Getters/Accessors
        ***********************/
        void getVertex(int);
        int getVertexCount();
        int getEdgeCount();
        void displayGraph();
        bool edgeExists(int, int);
        bool isEmpty();

        /***********************
        Setters/Mutators
        ***********************/
        bool addVertex(int, Data*);
        bool removeVertex(int);
        bool addEdge(int, int);
        bool removeEdge(int, int);

        /***********************
        Traversal methods
        ***********************/
        void breadthFirst(int);
        void depthFirst(int);
};

#endif //GRAPH_H