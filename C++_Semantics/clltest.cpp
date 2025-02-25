/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <iostream>
#include "linkedList.h"

/**
 *  Utility functions for test file:
 *  - printInt(): prints an integer value
 *  - squareInt(): squares and integer value
 *  - compareInt(): compare two integer values for equality
 *  - printFloat(): prints float value
 *  - doubleFloat(): doubles a float value
 *  = compareFloat(): compares two flot values for equality
 */
// Print Integer Function
void printInt(int &value) {
    std::cout << value << " ";
}

// Square Integer Function
void squareInt(int &value) {
    value = value * value;
}

// Print Float Function
void printFloat(float &value) {
    std::cout << value << " ";
}

// Double Float Function
void doubleFloat(float &value) {
    value *= 2;
}

// Main function
int main() {
    /**
     * Testing LinkedList with integers:
     * 1. create LinkedList object
     * 2. push several integers to list
     * 3. print list contents(using map())
     * 4. applying squareInt() to each int using map()
     * 5. print list again to double check squreInt()
     * 6. test remove() and find() using int's
     * 7. clear list and double check its empty
     */
    LinkedList<int> intList; // step 1
    std::cout << "Adding Integers to List:\n";
    for (int i = 0; i < 20; i += 2){
        intList.push(i); // step 2
    }
    intList.print(); // step 3

    std::cout << "After Squaring Integers:\n";
    intList.map(squareInt); // step 4
    intList.print(); // step 5

    std::cout << "Removing 8 From List:\n";
    intList.remove(8); // step 6
    intList.print();

    std::cout << "Size of Int List: " << intList.size() << std::endl;
    intList.clear(); // step 7
    std::cout << "After Clearing Int List:\n";
    intList.print(); 

    /**
     * Testing LinkedList w/ Floats:
     * 1. create LinkedList object for floats
     * 2. append several floats to list
     * 3. print list(use map())
     * 4. double each float(using map())
     * 5. test removing a single float value and doublecheck it was removed
     * 6. clear list and doublecheck if cleared
     */
    LinkedList<float> floatList; // step 1
    std::cout << "\nAdding Floats to List:\n";
    for (int i = 0; i < 5; i++) {
        floatList.append(i * 0.5f); // step 2
    }
    floatList.print(); // step 3

    std::cout << "After Doubling Floats:\n";
    floatList.map(doubleFloat); // step 4
    floatList.print();

    std::cout << "Removing 1.0 from Float List:\n";
    floatList.remove(1.0f); // step 5
    floatList.print();

    std::cout << "Size of Float List: " << floatList.size() << std::endl;
    intList.clear(); // step 6
    std::cout << "After Clearing Float List:\n";
    intList.print(); // step 7

    return 0;
}