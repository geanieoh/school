/* *************************************************************
Name: Eugenio Hernandez-Ocampo  
Assignment: Binary Search Tree Implementation  
Purpose: Implement a binary search tree with methods for insertion, 
         deletion, retrieval, traversal, and height calculation.
************************************************************** */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
 
#include <iostream>
#include "data.h"
 
class BinTree {
    public:
        /**********************
        * Constructor & Destructor
        **********************/
        BinTree();
        ~BinTree();
 
        /****************
        * Getters/Accessors
        ****************/
        bool isEmpty();
        int getCount();
        bool getRootData(Data*);
        int getHeight();
 
        /****************
        * Setters/Mutators
        ****************/
        void displayTree();
        void clear();
        bool addNode(int, const string*);
        bool removeNode(int);
        bool getNode(Data*, int);
        bool contains(int);
 
        /****************
        * Traversal Functions
        ****************/
        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();
 
    private:
        /****************
        * Private Helper Functions
        ****************/
        void clear(DataNode*);
        bool addNode(DataNode*, DataNode**);
        DataNode* removeNode(int, DataNode*);
        bool getNode(Data*, int, DataNode*);
        bool contains(int, DataNode*);
        int getHeight(DataNode*);
         
        /****************
        * Private Traversal Helpers
        ****************/
        void displayPreOrder(DataNode*);
        void displayPostOrder(DataNode*);
        void displayInOrder(DataNode*);
 
        /****************
        * Private Members
         ****************/
         DataNode* root;
         int count;
 };
 
 #endif /* BINTREE_BINTREE_H */ 