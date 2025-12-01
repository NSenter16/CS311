/**
 * @brief The implementation of the Linked List data structure
 */

//You must complete the  parts and then complete LinkedList.cpp. Delete "" after you are done.

//- Make sure description and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

// ====================================================
//Your name: Noah Senter
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
       Node* current = front;
    while(current != nullptr)
    {
        Node* nextNode = current->next; // save pointer to the next node
        delete current;                 //free memory from current node
        current = nextNode;             //pointer moves to next node
    }
    front = nullptr;
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
     //if head and tail both point to null then list is empty
    if(front == nullptr)
    {
        return true;
    }
    else{
        return false;
    }
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    //create a pointer that determines length
    //increment pointer until it reaches null
    int length = 0;
    Node* current = front;
    while(current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

//Adds a node to the tail of the list
//new node next points to null
void LinkedList::addRear(T val) {
    //create new node
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;
    if (front == nullptr)
    {
        front = newNode;
    } 
    else
    {
        Node* temp = front;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

//Adds a new node to the front of the list
//head points to new node
//new node next points to previous front node
void LinkedList::addFront(T val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = front;
    front = newNode;
} 

//Delete node front is pointing to
bool LinkedList::deleteFront(T &OldNum) {
    if (front == nullptr)
    {
        return false;       //List is empty, nothing to delete
    }

    Node* temp = front;
    OldNum = front->val;   //capture value before deleting
    front = front->next;    //move head forward
    delete temp;            //delete old front
    return true;
} 

//Delete node rear is pointing to
bool LinkedList::deleteRear(T &OldNum) {
    if (front == nullptr)
    {
        return false;           //list is empty
    }

    if(front->next == nullptr)
    {
        OldNum = front->val;
        delete front;
        front = nullptr;
        return true;
    }

    Node* temp = front;
    while (temp->next->next != nullptr) //stop at 2nd to last node
    {
        temp = temp->next;
    }

    OldNum = temp->next->val;
    delete temp->next;
    temp->next = nullptr;
    return true;
} 

/* --- harder ones for test 2 and 3 -- */

    /**
    * Implement the deleteAt function to delete a node at a given position.
    */
bool LinkedList::deleteAt(int pos, T &val) {
    if (front == nullptr||pos < 0)
    {
        return false;               //list is empty or invalid position
    }

    if (pos == 0)                   //when front node
    {
        Node* temp = front;
        val = front->val;
        front = front->next;
        delete temp;
        return true;
    }

    Node* temp = front;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++)    //when not front or rear node
    {
        temp = temp -> next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        return false;
    }

    Node* nodeToDelete = temp->next;
    val = nodeToDelete->val;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    return true;
}

    /**
     * Implement the insertAt function here.
     */
bool LinkedList::insertAt(int pos, T val) {
   if (pos < 0)                    // fails if pos is less than front node
    {
        return false;
    }
    
    if (pos == 0)                  // when new node is front node
    {
        addFront(val);
        return true;
    }

    Node* newNode = new Node();
    newNode->val = val;

    Node* temp = front;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++)    // when new node is not front or rear
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        delete newNode;
        return false;
    }


    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
   

       Node* current = other.front;
    while(current != nullptr)
    {
        addRear(current->val);
        current = current->next;
    }
    // for each node in the other list. The new node should have the same value as the other node.

}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList& LinkedList::operator=(const LinkedList &other) {
    if(this != &other) { // check if the same object
        Node* otherCurrent = other.front;
        while (otherCurrent != nullptr)
        {
            addRear(otherCurrent->val);
            otherCurrent = otherCurrent->next;
        }
    }
    return *this;
}

/**
 * Implement the search function.
 * 
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
 int LinkedList::search(const T& val) const {
    Node* CurrentNode = front;
    int i = 0;

    while(CurrentNode != nullptr)       //as long as there are still nodes in list
    {
        if(CurrentNode->val == val)    //if val==val, return val position
        {
            return i;
        }
        CurrentNode = CurrentNode->next;
        i++;
    }
    return -1;
}