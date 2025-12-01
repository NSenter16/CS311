/**
 * @brief You will implement the insertion sort and merge sort algorithms for a linked list in this file
 */
//You must complete the  parts and then complete LinkedList.cpp. Delete "" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

#include "sorting.h"

/**
 * Implement the insertion sort algorithm for Linkedlist correctly
 */
LinkedList insertionSortLL(const LinkedList& list, bool reversed) {
    LinkedList sortedList;
    Node* sortedHead = nullptr;

    // Copy nodes from input list
    Node* current = list.getHead();
    while (current) {
        Node* next = current->next;

        // Create a new node to insert into the sorted list
        Node* newNode = new Node(current->data);

        sortedHead = sortedInsert(sortedHead, newNode, reversed);
        current = next;
}

/**
 * Implement the merge sort algorithm for LinkedList correctly
 */
LinkedList mergeSortLL(const LinkedList& list, bool reversed) {
    // TODO: Add your code here
}
