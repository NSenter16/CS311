#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
T Heap::getMax() const {
    if(count == 0)
    {
        return -1;
    }

    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int capacity) {
    this->capacity = capacity;
    count = 0;
    heaparray = new T[capacity];
}

// @brief destructor
Heap::~Heap() {
    delete[] heaparray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(T *values, int length) {
    capacity = length;
    count = length;
    heaparray = new T[capacity];

    for(int i = 0; i < length; i++)     //transfers values from heaparray to values
    {
        heaparray[i] = values[i];
    }

    for(int i = count / 2 - 1; i >= 0; i--)
    {
        percolateDown(i);
    }
}

 /**
 * @brief Copy constructor
 * @param other the heap to be copied
 */
Heap::Heap(const Heap &other) {
    capacity = other.capacity;
    count = other.count;

    heaparray = new T[capacity];

    for(int i = 0; i < count; i++)     //transfers values from heaparray to other heaparray
    {
        heaparray[i] = other.heaparray[i];
    }
}

/**
* @brief Assignment operator
* @param other the heap to be copied
* @return Heap& a reference to the heap
*/
Heap & Heap::operator=(const Heap &other) {
    if(this == &other)
    {
        return *this;
    }
    
    delete[] heaparray;     //free memory

    //copy capacity and count
    capacity = other.capacity;
    count = other.count;
    heaparray = new T[capacity];

    for (int i = 0; i < count; i++)
    {
        heaparray[i] = other.heaparray[i];
    }
    return *this;
}


/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {

    //i represents the parent percolating down until child is smaller
   for(int i = count / 2 - 1; i >= 0; i--)
   {
    percolateDown(i);
   }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {
    //child parameters
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    //left child
    if(left < count && heaparray[left] > heaparray[largest])
    {
        largest = left;
    }

    //right child
    if(right < count && heaparray[right] > heaparray[largest])
    {
        largest = right;
    }

    //if the child is larger than parent, swap and recall
    if(largest != index)
    {
        swap(index, largest);
        percolateDown(largest); //call function again
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp(int index) {

    //case when at root
    if(index == 0)
    {
        return;
    }

    int parent = (index - 1) / 2;

    //if child is greater than parent, swap
    if (heaparray[index] > heaparray[parent])
    {
        swap(index, parent);
        percolateUp(parent);
    }
   
}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(T value) {

    //if array is full
    if(count == capacity)
    {
        cerr << "Heap is full\n";
        return;
    }

    //new value at end of array
    heaparray[count] = value;
    count ++;

    //resort property
    percolateUp(count - 1);
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
T Heap::removeMax() {
    if(count == 0)
    {
        cerr << "Heap is empty\n";
        return T();
    }

    T root = heaparray[0];

    //move last element to root
    heaparray[0] = heaparray[count - 1];
    count --;

    //reset heap
    percolateDown(0);

    return root;
}

//@brief converts the heap into a string
string Heap::toString()
{
    string s = "[ ";
    for (int i = 0; i < count; i++)
    {
        s += to_string(heaparray[i]) + " ";
    }
    s += "]";
    return s;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    cout << toString() << endl;
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    T temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}



//heapsort helper function
void percolateDown(T values[], int length, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //left child
    if(left < length && values[left] > values[largest])
    {
        largest = left;
    }

    //right child
    if(right < length && values[right] > values[largest])
    {
        largest = right;
    }

    //if largest is not root, swap and continue
    if(largest != i)
    {
        T temp = values[i];
        values[i] = values[largest];
        values[largest] = temp;

        percolateDown(values, length, largest);
    }
}
/**
 * @brief  Sorts the values of an array by using the heap
 */
void heapSort(T values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);

    //heapify max heap
    for(int i = length / 2 - 1; i >= 0; i--)
    {
        percolateDown(values, length, i);
    } 

    //extract elements from heap
    for(int i = length -1; i > 0; i--)
    {
        T temp = values[0];
        values[0] = values[i];
        values[i] = temp;

        //call percolate down
        percolateDown(values, i, 0);
    }


    cout << "Array After Sorting: \n";
    printArray(values, length);

    return;
}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, T new_val) {

   //invalid index manage 
   if(i < 0 || i >= count)
   {
    cerr << "Invalid index\n";
   }

   //old value = current value, change current value to new value
   T oldValue = heaparray[i];
   heaparray[i] = new_val;

   //if new value is greater than old value, percolate up, otherwise percolate down
   if(new_val > oldValue)
   {
    percolateUp(i);
   }
   else if(new_val < oldValue)
   {
    percolateDown(i);
   }
}
