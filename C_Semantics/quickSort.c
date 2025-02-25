/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	int a = *(int *)p;
    int b = *(int *)q;

    // if both are even number then sort in descending order
    if (a % 2 == 0 && b % 2 == 0) {
        return b - a;
    }

    // if both are odd number then sort in ascending order
    if (a % 2 != 0 && b % 2 != 0) {
        return a - b;
    }

    // if one is even while the other is odd then we regard even number to higher priority
    if (a % 2 == 0) {
        return -1; // a comes before b
    }
    return 1; // b comes before a
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}