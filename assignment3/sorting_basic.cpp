/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"

/**
 * Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
        //For loop that sets up insertion
        //i starts at second number in array and compares it to the previous number j
        for (int i = lowindex + 1; i <= highindex; i++) {
        int key = array[i];
        int j = i - 1;

        //If numbers are in ascending order, swap number positions
        if (!reversed) {
            // Ascending order
            while (j >= lowindex && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
        //If numbers are in descending order, move to next number
        } else {
            // Descending order
            while (j >= lowindex && array[j] < key) {
                array[j + 1] = array[j];
                j--;
            }
        }
        //move key pointer to next number
        array[j + 1] = key;
    }
}

/**
 * @brief Implementation of the partition function used by quick sort
 * 
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    int midpoint = lowindex + (highindex - lowindex) / 2;
    int pivot = array[midpoint];

    bool done = false;
    while(!done)
    {
        while ((!reversed && array[lowindex] < pivot) || (reversed && array[lowindex] > pivot)) {
            lowindex++;
            }
        while ((!reversed && array[highindex] > pivot) || (reversed && array[highindex] < pivot)) {
            highindex--;
        }

        if(lowindex >= highindex)
        {  
            done = true;
        }
        else // swap low and high index positions
        {
            int temp = array[lowindex];
            array[lowindex] = array[highindex];
            array[highindex] = temp;

            //adjust low and high index
            highindex --;
            lowindex ++;
        }
    }
    return highindex; //represents highest index of low partition
}

/**
 * Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    if (lowindex >= highindex) 
    {
        return;
    }

    int lowendindex = partition(array, lowindex, highindex, reversed);  //adjust lowendindex to be the highindex of the smaller array
    
    //Call function recursively to make smaller and smaller arrays while adjusting lowendindex
    quickSort(array, lowindex, lowendindex, reversed); 
    quickSort(array, lowendindex + 1, highindex, reversed);
}


