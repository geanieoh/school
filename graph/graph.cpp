/**************************************************************
Name: Eugenio Hernandez-Ocampo
Assignment: Final Project
Purpose: Implement a graph data structure with vertices and 
         edges and operations like adding/removing 
         vertices and edges, and traversals. Can contain up to
         1000 vertices.
***************************************************************/

#include "graph.h"

Graph::Graph() : head(nullptr), vertexCount(0), edgeCount(0) {}

Graph::~Graph(){
    /* ******************************************
    Destructor for the Graph class. Cleans up all dynamically 
    allocated memory for vertices and edges in the graph.

    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    Vertex* current = head;
    while(current){
        Vertex* nextVertex = current->next;
        Edge* edge = current->adjacencyList;
        while(edge){
            Edge* nextEdge = edge->next;
            delete edge;
            edge = nextEdge;
        }
        delete current->data;
        current->data = nullptr;

        delete current;
        current = nextVertex;
    }
    head = nullptr;
    vertexCount = 0;
    edgeCount = 0;
}

Graph::Vertex* Graph::findVertex(int id){
    /* ******************************************
    Finds a vertex in the graph by its ID.

    @param id (int) : the ID of the vertex to find
    @return (Vertex*) : pointer to the vertex if found, nullptr otherwise
    @exception na : na
    * *******************************************/
    Vertex* current = head;
    while(current && current->id != id){
        current = current->next;
    }

    return current;
}

bool Graph::edgeExists(Vertex* start, Vertex* end){
    /* ******************************************
    Checks if an edge exists from start vertex to end vertex.

    @param start (Vertex*) : pointer to the start vertex
    @param end (Vertex*) : pointer to the end vertex
    @return (bool) : true if the edge exists, false otherwise
    @exception na : na
    * *******************************************/
    bool result = false;

    if(start && end && result == false){
        Edge* currentEdge = start->adjacencyList;
        while(currentEdge){
            if(currentEdge->destination == end){
                result = true;
            }
            currentEdge = currentEdge->next;
        }
    }

    return result;
}

bool Graph::isEmpty(){
    /* ******************************************
    Checks if the graph is empty (no vertices).

    @param na : na
    @return (bool) : true if graph has no vertices, false otherwise
    @exception na : na
    * *******************************************/
    return vertexCount == 0;
}

int Graph::getVertexCount(){
    /* ******************************************
    Returns the current number of vertices in the graph.

    @param na : na
    @return (int) : vertex count
    @exception na : na
    * *******************************************/
    return vertexCount;
}

int Graph::getEdgeCount(){
    /* ******************************************
    Returns the current number of edges in the graph.

    @param na : na
    @return (int) : edge count
    @exception na : na
    * *******************************************/
    return edgeCount;
}

bool Graph::edgeExists(int startID, int endID){
    /* ******************************************
    Checks if an edge exists between vertices by their IDs.

    @param startID (int) : ID of start vertex
    @param endID (int) : ID of end vertex
    @return (bool) : true if edge exists, false otherwise
    @exception na : na
    * *******************************************/
    Vertex* start = findVertex(startID);
    Vertex* end = findVertex(endID);
    return edgeExists(start, end);
}

bool Graph::addVertex(int id, Data* data){
    /* ******************************************
    Adds a new vertex to the graph if ID is unique.

    @param id (int) : ID of new vertex
    @param data (Data*) : pointer to vertex data
    @return (bool) : true if vertex was added, false if ID exists
    @exception na : na
    * *******************************************/
    bool result = false;

    if(findVertex(id) == nullptr){
        Vertex* newVertex = new Vertex;
        newVertex->id = id;
        newVertex->data = data;
        newVertex->adjacencyList = nullptr;

        newVertex->next = head;
        head = newVertex;

        vertexCount++;
        result = true;
    }

    return result;
}

void Graph::removeAllEdgesTo(Vertex* target){
    /* ******************************************
    Removes all edges that point to the specified target vertex.

    @param target (Vertex*) : pointer to the vertex to remove incoming edges for
    @return na : na
    @exception na : na
    * *******************************************/
    if(target){
        Vertex* current = head;
        while(current){
            if(current != target){
                Edge** indirect = &(current->adjacencyList);
                while(*indirect){
                    if((*indirect)->destination == target){
                        Edge* toDelete = *indirect;
                        *indirect = toDelete->next;
                        delete toDelete;
                        edgeCount--;
                    }
                    else{
                        indirect = &((*indirect)->next);
                    }
                }
            }
            current = current->next;
        }
    }
}

bool Graph::removeVertex(int id){
    /* ******************************************
    Removes a vertex and all its associated edges from the graph.

    @param id (int) : ID of the vertex to remove
    @return (bool) : true if vertex was removed, false if not found
    @exception na : na
    * *******************************************/
    bool result = false;
    Vertex** indirect = &head;
    while(*indirect && result == false){
        if((*indirect)->id == id){
            Vertex* toDelete = *indirect;
            removeAllEdgesTo(toDelete);
            Edge* edge = toDelete->adjacencyList;
            while(edge){
                Edge* nextEdge = edge->next;
                delete edge;
                edge = nextEdge;
            }
            *indirect = toDelete->next;
            delete toDelete->data;
            toDelete->data = nullptr;
            delete toDelete;
            vertexCount--;
            result = true;
        }
        else{
            indirect = &((*indirect)->next);
        }
    }
    return result;
}

bool Graph::addEdge(int startID, int endID){
    /* ******************************************
    Adds an undirected edge between two vertices by their IDs.

    @param startID (int) : ID of start vertex
    @param endID (int) : ID of end vertex
    @return (bool) : true if edge was added, false otherwise
    @exception na : na
    * *******************************************/
    bool result = false;
    if(startID != endID){
        Vertex* start = findVertex(startID);
        Vertex* end = findVertex(endID);
        if(start && end && !edgeExists(start, end)){
            Edge* newEdge1 = new Edge;
            Edge* newEdge2 = new Edge;

            newEdge1->destination = end;
            newEdge1->next = start->adjacencyList;
            start->adjacencyList = newEdge1;

            newEdge2->destination = start;
            newEdge2->next = end->adjacencyList;
            end->adjacencyList = newEdge2;

            edgeCount++;
            result = true;
        }
    }
    return result;
}

bool Graph::removeEdge(int startID, int endID){
    /* ******************************************
    Removes an undirected edge between two vertices by their IDs.

    @param startID (int) : ID of start vertex
    @param endID (int) : ID of end vertex
    @return (bool) : true if edge was removed, false otherwise
    @exception na : na
    * *******************************************/
    bool result = false;
    Vertex* start = findVertex(startID);
    Vertex* end = findVertex(endID);

    if(start && end){
        Edge** indirect = &(start->adjacencyList);
        while(*indirect){
            if((*indirect)->destination == end){
                Edge* toDelete = *indirect;
                *indirect = toDelete->next;
                delete toDelete;
                edgeCount--;
                result = true;
                break;
            }
            indirect = &((*indirect)->next);
        }

        Edge** reverseIndirect = &(end->adjacencyList);
        while(*reverseIndirect){
            if((*reverseIndirect)->destination == start){
                Edge* toDelete = *reverseIndirect;
                *reverseIndirect = toDelete->next;
                delete toDelete;
                break;
            }
            reverseIndirect = &((*reverseIndirect)->next);
        }
    }

    return result;
}

void Graph::getVertex(int id){
    /* ******************************************
    Prints the data associated with a vertex.

    @param id (int) : ID of vertex to display
    @return na : na
    @exception na : na
    * *******************************************/
    Vertex* vertex = findVertex(id);
    if(vertex){
        std::cout << "vertex " << vertex->id << " data:\n\tvalue: " << vertex->data->val << "\tinfo: " << vertex->data->information << std::endl;
    }
    else{
        std::cout << "failed to retrieve vertex " << id << std::endl;
    }
}

void Graph::displayGraph(){
    /* ******************************************
    Displays the graph adjacency information to the console.

    @param na : na
    @return na : na
    @exception na : na
    * *******************************************/
    std::cout << "=== Displaying Graph ===" << std::endl;
    if(!isEmpty()){
        Vertex* currentVertex = head;
        while(currentVertex){
            std::cout << "vertex " << currentVertex->id << " has an edge connecting to: ";
            Edge* currentEdge = currentVertex->adjacencyList;
            if(currentEdge){
                while(currentEdge){
                    std::cout << "vertex " << currentEdge->destination->id << ", ";
                    currentEdge = currentEdge->next;
                }
            }
            std::cout << std::endl;
            currentVertex = currentVertex->next;
        }
    }
    else{
        std::cout << "graph is empty" << std::endl;
    }
    std::cout << std::endl;
}

void Graph::breadthFirst(int startID){
    /* ******************************************
    Performs a breadth first traversal of the graph starting from a vertex ID.

    @param startID (int) : ID of the start vertex
    @return na : na
    @exception na : na
    * *******************************************/
    Vertex* start = findVertex(startID);
    if(start){
        bool visited[MAX_VERTICES] = { false };

        Vertex* queue[MAX_VERTICES];
        int front = 0;
        int rear = 0;

        visited[start->id] = true;
        queue[rear++] = start;

        std::cout << "breadth first traversal starting at vertex " << start->id << ":\n\t";

        while(front < rear){
            Vertex* current = queue[front++];
            std::cout << current->id << " --> ";

            Edge* edge = current->adjacencyList;
            while(edge){
                Vertex* neighbor = edge->destination;
                if(!visited[neighbor->id]){
                    visited[neighbor->id] = true;
                    queue[rear++] = neighbor;
                }
                edge = edge->next;
            }
        }

        std::cout << std::endl;
    }
    else{
        std::cout << "start vertex not found.\n";
    }
}

void Graph::depthFirst(int startID){
    /* ******************************************
    Performs a depth first traversal of the graph starting from a vertex ID.

    @param startID (int) : ID of the start vertex
    @return na : na
    @exception na : na
    * *******************************************/
    Vertex* start = findVertex(startID);
    if(start){
        bool visited[MAX_VERTICES] = { false };
        Vertex* stack[MAX_VERTICES];
        int top = -1;
        stack[++top] = start;
        std::cout << "depth first traversal starting at vertex " << start->id << ":\n\t";

        while(top >= 0){
            Vertex* current = stack[top--];
            if(!visited[current->id]){
                std::cout << current->id << " --> ";
                visited[current->id] = true;
                Edge* edge = current->adjacencyList;
                Vertex* neighbors[MAX_VERTICES];
                int neighborCount = 0;

                while(edge){
                    if(!visited[edge->destination->id]){
                        neighbors[neighborCount++] = edge->destination;
                    }
                    edge = edge->next;
                }

                for (int i = neighborCount - 1; i >= 0; --i) {
                    stack[++top] = neighbors[i];
                }
            }
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start vertex not found.\n";
    }
}