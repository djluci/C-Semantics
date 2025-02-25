/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <iostream> // input-output operations
#include <vector> // utilizing vector container
#include <string> // for string data types

using namespace std;

/**
 * Perform Bubble sort
 * function works with any data type that supports '>' operator,
 * sorts the elements of a vector in ascending order by constantly swapping
 * adjacent elements if they are in the wrong order 
 * 
 * 
 * @param arr: reference to vector that needs to be sorted
*/
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size(); // acquiring size of vector
    // loop through every element in the vector
    for (int i = 0; i < n - 1; i++) {
        // the inner loop so we can compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // if present element is greater than the next one we swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

/**
 * function to print the elements of a vector.
 * supports any data type that supports output streaming.
 * 
 * @param arr: A constant reference to the vector to be printed.
 */
template <typename T>
void printArray(const vector<T>& arr) {
    // loops through vector and prints each element
    for (const auto& elem : arr) {
        cout << elem << " ";  // Print each element followed by a space
    }
    cout << endl;  // Print a newline at the end
}

/**
 * Main function to demonstrate Bubble Sort algorithm.
 * sorts three different types of data: integers, floats, and strings.
 */
int main() {
    // Example 1: Sorting integers
    vector<int> intArray = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original integer array: ";
    printArray(intArray);  // Print original integer array
    bubbleSort(intArray);  // Sort the integer array
    cout << "Sorted integer array: ";
    printArray(intArray);  // Print sorted integer array

    // Example 2: Sorting floating-point numbers
    vector<float> floatArray = {64.5, 34.1, 25.6, 12.3, 22.8, 11.9, 90.7};
    cout << "\nOriginal float array: ";
    printArray(floatArray);  // Print original float array
    bubbleSort(floatArray);  // Sort the float array
    cout << "Sorted float array: ";
    printArray(floatArray);  // Print sorted float array

    // Example 3: Sorting strings
    vector<string> stringArray = {"banana", "apple", "orange", "grape", "pear"};
    cout << "\nOriginal string array: ";
    printArray(stringArray);  // Print original string array
    bubbleSort(stringArray);  // Sort the string array
    cout << "Sorted string array: ";
    printArray(stringArray);  // Print sorted string array

    return 0;  // Returns 0 to show program was successful
}