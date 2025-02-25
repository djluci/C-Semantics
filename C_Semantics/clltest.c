/*
        Bruce Maxwell
        Fall 2012
        CS 333

        Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

// function that prints an integer
void printInt(void *i) {
    int *a = (int *)i;

    printf("value: %d\n", *a);
}

// function that squares an integer
void squareInt(void *i) {
    int *a = (int *)i;

    *a = *a * *a;
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
    int *a = (int *)i;
    int *b = (int *)j;

    return (*a == *b);
}

/**
 * Extending test file so linked list is used with a second data type.
 * Second data type is floating-point numbers
 */

// prints float
void printFloat(void *f) {
    float *a = (float *)f;
    printf("value: %.2f\n", *a);
}

//multiplies a float by 2
void doubleFloat(void *f) {
    float *a = (float *)f;
    *a *= 2;
}

// compares floats 
int compFloat(void *f1, void *f2) {
    float *a = (float *)f1;
    float *b = (float *)f2;
    return (*a == *b);
}

// Main function to test linked list operations with multiple data types
int main(int argc, char *argv[]) {
    LinkedList *l;
    int *a, *target;
    float *f;
    int i;

    // Create a linked list
    l = ll_create();

    // Push integers onto the list
    for (i = 0; i < 20; i += 2) {
        a = malloc(sizeof(int));
        *a = i;
        ll_push(l, a);
    }

    // Print the integer list and apply the square function
    printf("After initializing with integers:\n");
    ll_map(l, printInt);

    ll_map(l, squareInt);

    printf("\nAfter squaring the integers:\n");
    ll_map(l, printInt);

    // Test removing and finding integers
    target = malloc(sizeof(int));
    *target = 16;
    a = ll_remove(l, target, compInt);
    if (a != NULL) {
        printf("\nRemoved integer: %d\n", *a);
        free(a);
    } else {
        printf("\nNo instance of %d found\n", *target);
    }

    *target = 11;
    a = ll_find(l, target, compInt);
    if (a != NULL) {
        printf("\nFound integer: %d\n", *a);
    } else {
        printf("\nNo instance of %d found\n", *target);
    }
    free(target);

    // Clear the integer list
    ll_clear(l, free);
    printf("\nAfter clearing the integer list:\n");
    ll_map(l, printInt);

    // Rebuild the list with floats and test float operations
    printf("\nTesting with floats:\n");
    for (i = 0; i < 5; i++) {
        f = malloc(sizeof(float));
        *f = (float)i / 2;
        ll_append(l, f);
    }

    printf("After appending floats:\n");
    ll_map(l, printFloat);

    ll_map(l, doubleFloat);

    printf("\nAfter doubling the floats:\n");
    ll_map(l, printFloat);

    // Test removing a float
    f = malloc(sizeof(float));
    *f = 1.00;
    void *removedFloat = ll_remove(l, f, compFloat);
    if (removedFloat != NULL) {
        printf("\nRemoved float: %.2f\n", *(float *)removedFloat);
        free(removedFloat);
    } else {
        printf("\nNo instance of %.2f found\n", *f);
    }
    free(f);

    // Clear the float list
    ll_clear(l, free);
    printf("\nAfter clearing the float list:\n");
    ll_map(l, printFloat);

    // Clean up the list
    free(l);

    return 0;
}