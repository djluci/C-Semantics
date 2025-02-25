/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <stdio.h>
#include <stdlib.h>

// computes factorial of a given integer 'n',
// function returns a long long integer to handle large results
// for a negative input it will return -1 to show its an error
long long factorial(const int n) {
    if (n < 0) {
        // negative input so it should print error
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }
    // 0! and 1! both return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // initialize the result to 1(* by 1 doesnt change value)
    long long result = 1;

    // muliply result by each number(from 2-n)
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result; //returns computed factorial
}

int main(int argc, char *argv[]) {
    //declares pointer for point to factorial function
    long long (*calc)(const int) = factorial;

    // check if theres exactly one command-line argument
    if (argc != 2) {
        // print usage message if the correct input wasn't provided
        printf("Usage: %s <positive integer>\n", argv[0]);
        return 1; // exit with error code(1) 
    }

    // convert command-line argument(string -> integer)
    int n = atoi(argv[1]);

    // call function using function pointer
    long long result = calc(n);

    // if result = -1 then error(invalid input)
    if (result != -1) {
        // print factorial result
        printf("The factorial of %d is: %lld\n", n, result);
    }
    return 0; // exit
}