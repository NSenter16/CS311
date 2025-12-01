/**
 * Implementation of BST class.
 */
//You must complete the  parts and then complete LinkedList.cpp. Delete "" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Noah Senter
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}


//Helper clear function
void BST::clear(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    clear(node->leftChild); //delete left substree
    clear(node->rightChild);    //delete right subtree
    delete node;                //delete current node
}


/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    clear(root);
    root = nullptr;
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
    //if empty or if leaf node, return true
    if(root == nullptr)
    {
        root = new Node(element);
        numElements ++;
        return true;
    }
    Node* current = root;
    Node* Parent = nullptr;

    //while not a leaf node
    while(current != nullptr)
    {
        Parent = current;
        //if element is a duplicate return false
        if(element == current->data)
        {
            return false;
        }
        //if element is less than the current value, go to left child
        else if(element < current->data)
        {
            current = current->leftChild;
        }
        //otherwise, go to right child
        else
        {
            current = current->rightChild;
        }
    }
    Node* newNode = new Node(element);
    newNode->parent = Parent;

    if(element < Parent->data)
    {
        Parent->leftChild = newNode;
    }
    else
    {
        Parent->rightChild = newNode;
    }
    numElements++;
    return true;
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    Node *current = root;
    while(current != nullptr)   //while there are still nodes beneath current node
    {
        if(query == current->data)  //if number is the current node data
        {
            return true;        //found
        }
        else if(query < current->data)  //if number is less than current node data
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;  //if number is greater than current node data
        }
        
    }
    return false;   //not found
}



//height helper implementation
int BST::height(Node* node) const
{
    if (node == nullptr) //if leaf node
    {
        return -1;
    }
    int leftHeight = height(node->leftChild);    //recall height function with left child
    int rightHeight = height(node->rightChild);  //recall height function with right child

    if(leftHeight > rightHeight)    //return whichever height is greater
    {
        return 1 + leftHeight;
    }
    else
    {
        return 1 + rightHeight;
    }
}
/**
 * Implement the height() function correctly
 */
int BST::height() const 
    {
        return height(root);
    }

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot()
    {
        if(numElements == 0)    //number of elements returns to 0 and returns the root node
        {
            return nullptr;
        }
        else
        {
            return root;    
        }
    }

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {
    if(node == nullptr) //if pointer is at nullptr
    {
        return; //go back to previous number
    }
    //travel to left child
    //when leftChild reaches null, recursion stops running this function
    printInorder(node->leftChild);  
    cout << node->data << " | ";    //print node data
    //runs after all left children have been printed
    printInorder(node->rightChild); //travel to right child
}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
void BST::printPreorder(Node* node) {
    if(node == nullptr) //if pointer is at nullptr
    {
        return; //go back to previous number
    }

    cout << node->data << " | ";    //print node data
    //travel to left child
    //when leftChild reaches null, recursion stops running this function
    printPreorder(node->leftChild);
    printPreorder(node->rightChild); //travel to right child
}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
void BST::printPostorder(Node* node) {
    if(node == nullptr)
    {
        return; //go back to previous node
    }

    //travel to left child
    //when leftChild reaches null, recursion stops running this function
    printPostorder(node->leftChild);
    printPostorder(node->rightChild);   //travel to right child
    cout << node->data << " | ";    //print node data
}


BST::Node *BST::getLeftMostNode(Node* node)
{
    if(node == nullptr)
    {
        return nullptr; //empty tree
    }
    Node *current = node;
    while(current->leftChild != nullptr)
    {
        current = current->leftChild; //move node left
    }
    return current;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node *BST::getLeftMostNode() 
{
    return getLeftMostNode(root);
}

/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node) {
    Node *current = node;
    if(node->rightChild != nullptr)
    {
        return getLeftMostNode(node->rightChild);
    }
    else
    {
        while(current->parent != nullptr && current->parent->rightChild == current)
        {
            current = current->parent;

        }
    }
        return current->parent;    
}

