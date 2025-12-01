/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */
//You must complete the  parts and then complete LinkedList.cpp. Delete "" after you are done.

#include "linkedlist.h"

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {

    LinkedList L3;
    Node* CurrentNode = LA.front;    //create new link list and point at front of L1

    while(CurrentNode != nullptr)       //while there are still nodes in L1, add val to rear of CurrentNode
    {
        if(L3.search(CurrentNode->val == -1))
        {
            L3.addRear(CurrentNode->val);
        }
        CurrentNode = CurrentNode->next;        
    }

    CurrentNode = LB.front;             //move currentnode to front of LB

    while(CurrentNode != nullptr)       //while there are still nodes in L1, add val to rear of CurrentNode
    {
        if(L3.search(CurrentNode->val) == -1)
        {
            L3.addRear(CurrentNode->val);     
        }
     
        CurrentNode = CurrentNode->next;
    }
    return L3;

}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList L3;

    //New node pointers 
    Node* P1 = LA.front;
    Node* P2 = LB.front;

    while(P1 != nullptr && P2 != nullptr)       //while there are still values for both p1 and p2
    {
        if(P1->val <= P2->val)          //if P1's value is smaller or equal to P2 value, add value to L3
        {
            L3.addRear(P1->val);
            P1 = P1->next;
        }
        else
        {
            L3.addRear(P2->val);        //else add P2 value to L3
            P2 = P2->next;
        }
    }

    while(P1 != nullptr)            //while there are still p1 values, add p1 values to L3
    {
        L3.addRear(P1->val);
        P1 = P1->next;
    }

    while(P2 != nullptr)            //while there are still p2 values, add p2 values to L3
    {
        L3.addRear(P2->val);
        P2 = P2->next;
    }
    return L3;
}