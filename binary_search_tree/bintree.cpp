/* *************************************************************
Name: Eugenio Hernandez-Ocampo  
Assignment: Binary Search Tree Implementation  
Purpose: Implement a binary search tree with methods for insertion, 
         deletion, retrieval, traversal, and height calculation.
************************************************************** */

#include "bintree.h"

BinTree::BinTree(){
    /* ******************************************
    Constructor: Initializes an empty binary search tree.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    root = nullptr;
    count = 0;
}
 
BinTree::~BinTree() {
    /* ******************************************
    Destructor: Clears the tree to release allocated memory.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    clear();
}
 
bool BinTree::isEmpty() {
    /* ******************************************
    Checks if the tree is empty.

    @param na : na
    @return (bool) : true if tree is empty, false otherwise
    @exception na : na
    *******************************************/
    return root == nullptr;
}
 
int BinTree::getCount() {
    /* ******************************************
    Returns the number of nodes in the tree.

    @param na : na
    @return (int) : number of nodes in the tree
    @exception na : na
    *******************************************/
    return count;
}
 
bool BinTree::getRootData(Data* data) {
    /* ******************************************
    Retrieves the data from the root node.

    @param (Data*) data : Pointer to store root data
    @return (bool) : true if root exists, false otherwise
    @exception na : na
    *******************************************/
    bool result;
    if (isEmpty()) {
        data->id = -1;
        data->information = "";
        result = false;
    } 
    else {
        *data = root->data;
        result = true;
    }
 
    return result;
}
 
void BinTree::displayTree() {
    /* ******************************************
    Displays the structure and contents of the tree.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    std::cout << "DISPLAY TREE" << std::endl;
    if(isEmpty()){
        std::cout << "Tree is empty" << std::endl;
    }
    else{
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height: " << getHeight() << std::endl;
    std::cout << "Node Count: " << getCount() << std::endl;
    std::cout << "Pre-order traversal:" << std::endl;
    displayPreOrder();
    std::cout << "In-order traversal:" << std::endl;
    displayInOrder();
    std::cout << "Post-order traversal:" << std::endl;
    displayPostOrder();
    std::cout << std::endl;
}
 
void BinTree::clear() {
    /* ******************************************
    Clears the entire tree and resets the root pointer.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    clear(root);
    root = nullptr;
    count = 0;
}
 
void BinTree::clear(DataNode* node) {
    /* ******************************************
    Helper function to clear the tree recursively.

    @param (DataNode*) node : Pointer to the current node
    @return na : na
    @exception na : na
    *******************************************/
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
 
bool BinTree::addNode(int id, const string* data) {
    /* ******************************************
    Inserts a new node into the binary search tree.

    @param (int) id : The ID of the node
    @param (const string*) data : Pointer to data associated with the ID
    @return (bool) : true if insertion is successful, false otherwise
    @exception na : na
    *******************************************/
    DataNode* newNode = new DataNode{id, *data, nullptr, nullptr};
    return addNode(newNode, &root);
}
 
bool BinTree::addNode(DataNode* newNode, DataNode** node) {
    /* ******************************************
    Helper function for node insertion (recursive).

    @param (DataNode*) newNode : The node to insert
    @param (DataNode**) node : Pointer to the current node
    @return (bool) : true if insertion is successful, false otherwise
    @exception na : na
    *******************************************/
    bool result;
    if (*node == nullptr) {
        *node = newNode;
        count++;
        result = true;
    }
    else if (newNode->data.id < (*node)->data.id) {
        result = addNode(newNode, &((*node)->left));
    }
    else {
        result = addNode(newNode, &((*node)->right));
    }
 
    return result;
}
 
bool BinTree::removeNode(int id) {
    /* ******************************************
    Removes a node from the tree by ID.

    @param (int) id : ID of the node to remove
    @return (bool) : true if successful, false otherwise
    @exception na : na
    *******************************************/
    root = removeNode(id, root);
    return root != nullptr;
}
 
DataNode* BinTree::removeNode(int id, DataNode* node) {
    /* ******************************************
    Helper function to remove a node (recursive).

    @param (int) id : ID of the node to remove
    @param (DataNode*) node : Pointer to the current node
    @return (DataNode*) : Updated node pointer
    @exception na : na
    *******************************************/
    DataNode* result;
    if (node == nullptr) {
        result = nullptr;
    }
    else if (id < node->data.id) {
        node->left = removeNode(id, node->left);
        result = node;
    } 
    else if (id > node->data.id) {
        node->right = removeNode(id, node->right);
        result = node;
    } 
    else {
        if (node->left == nullptr) {
            result = node->right;
            delete node;
            count--;
        } 
        else if (node->right == nullptr) {
            result = node->left;
            delete node;
            count--;
        } 
        else {
            DataNode* replacementParent = node;
            DataNode* replacement = node->right;
 
            while (replacement->left != nullptr) {
                replacementParent = replacement;
                replacement = replacement->left;
            }
 
            node->data = replacement->data;
 
            if(replacementParent->left == replacement){
                replacementParent->left = removeNode(replacement->data.id, replacement);
            }
            else{
                replacementParent->right = removeNode(replacement->data.id, replacement);
            }
             
            result = node;
        }
    }
    return result;
}
 
bool BinTree::contains(int id) {
    /* ******************************************
    Checks if a node with the given ID exists in the tree.

    @param (int) id : ID to search for
    @return (bool) : true if the node exists, false otherwise
    @exception na : na
    *******************************************/
    return contains(id, root);
}
 
bool BinTree::contains(int id, DataNode* node) {
    /* ******************************************
    Helper function to check if a node exists (recursive).

    @param (int) id : ID to search for
    @param (DataNode*) node : Pointer to the current node
    @return (bool) : true if the node exists, false otherwise
    @exception na : na
    *******************************************/
    bool result;
    if (node == nullptr) {
        result = false;
    }
    else if (id == node->data.id) {
        result = true;
    }
    else if (id < node->data.id) {
        result = contains(id, node->left);
    } 
    else {
        result = contains(id, node->right);
    }
 
    return result;
}
 
bool BinTree::getNode(Data* data, int id) {
    /* ******************************************
    Retrieves the data of a node with the given ID.

    @param (Data*) data : Pointer to store retrieved data
    @param (int) id : ID of the node to retrieve
    @return (bool) : true if node exists, false otherwise
    @exception na : na
    *******************************************/
    return getNode(data, id, root);
}
 
bool BinTree::getNode(Data* data, int id, DataNode* node) {
    /* ******************************************
    Helper function to retrieve a node’s data (recursive).

    @param (Data*) data : Pointer to store retrieved data
    @param (int) id : ID of the node to retrieve
    @param (DataNode*) node : Pointer to the current node
    @return (bool) : true if node exists, false otherwise
    @exception na : na
    *******************************************/
    bool result;
    if (node == nullptr) {
        result = false;
    }
    else if (id == node->data.id) {
        *data = node->data;
        result = true;
    }
    else if (id < node->data.id) {
        result = getNode(data, id, node->left);
    } 
    else {
        result = getNode(data, id, node->right);
    }
 
    return result;
}
 
int BinTree::getHeight() {
    /* ******************************************
    Computes the height of the binary search tree.

    @param na : na
    @return (int) : Height of the tree
    @exception na : na
    *******************************************/
    return getHeight(root);
}
 
int BinTree::getHeight(DataNode* node) {
    /* ******************************************
    Helper function to compute tree height recursively.

    @param (DataNode*) node : Pointer to the current node
    @return (int) : Height of the subtree
    @exception na : na
    *******************************************/
    int result;
    if (node == nullptr) {
        result = 0;
    }
    else{
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        result = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
     
    return result;
}
 
void BinTree::displayPreOrder() {
    /* ******************************************
    Displays the tree using pre-order traversal.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    displayPreOrder(root);
}
 
void BinTree::displayPreOrder(DataNode* node) {
    /* ******************************************
    Helper function for pre-order traversal (recursive).

    @param (DataNode*) node : Pointer to the current node
    @return na : na
    @exception na : na
    *******************************************/
    if (node != nullptr) {
        std::cout << node->data.id << ": " << node->data.information << std::endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}
 
void BinTree::displayPostOrder() {
    /* ******************************************
    Displays the tree using post-order traversal.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    displayPostOrder(root);
}
 
void BinTree::displayPostOrder(DataNode* node) {
    /* ******************************************
    Helper function for post-order traversal (recursive).

    @param (DataNode*) node : Pointer to the current node
    @return na : na
    @exception na : na
    *******************************************/
    if (node != nullptr) {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        std::cout << node->data.id << ": " << node->data.information << std::endl;
    }
}
 
void BinTree::displayInOrder() {
    /* ******************************************
    Displays the tree using in-order traversal.

    @param na : na
    @return na : na
    @exception na : na
    *******************************************/
    displayInOrder(root);
}
 
void BinTree::displayInOrder(DataNode* node) {
    /* ******************************************
    Helper function for in-order traversal (recursive).

    @param (DataNode*) node : Pointer to the current node
    @return na : na
    @exception na : na
    *******************************************/
    if (node != nullptr) {
        displayInOrder(node->left);
        std::cout << node->data.id << ": " << node->data.information << std::endl;
        displayInOrder(node->right);
    }
}