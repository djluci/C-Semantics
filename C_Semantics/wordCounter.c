/**
 * Duilio Lucio
 * 10/06/2024
 */

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    /**
     * Check Command-Line Arguments:
     * 1.verify program receives only one argument(filename)
     * 2. Exit if there's no/incorrect # of arguments
     */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /**
     * Open file:
     * 1. utilize fopen to open file provided by command=line argurment.
     * 2. if file doesnt open print error message
     */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        perror("Error Opening File");
        return 1;
    } 

    /**
     * Create linked list:
     * 1. initialize new linkedList in order to be able to store words and their frequencies
     * 2. Buffer in order to store each word read from file
     */
    LinkedList *list = ll_create();
    char word[256];

    /**
     * Read words from file:
     * 1. loop through each word in file using fscanf
     * 2. for each word remove the punctuation using helper function
     * 3. convert word to lowercase in order to handle case insensitivity
     * 4. if processed word isn't empty then we add to linked list
     * 5. if word exists we increment its frequency
     * 6. if word doesnt exist we add a new node with frequency of 1
     */
    while (fscanf(file, "%255s", word) == 1){
        remove_punctuation(word);
        to_lowercase(word);
        if (strlen(word) > 0) {
            ll_push_or_increment(list, word);
        }
    }
    /**
     * Close file:
     * 1. after reading all the words use fclose to close the file
     */
    fclose(file);

    /**
     * sort linkedList by frequency:
     * 1. sort nodes in linkedList in descending order based on their frequency
     */
    ll_sort(list);

    /**
     * Print top 20 words:
     * 1. print the first 20 sorted nodes in linkedList
     */
    ll_print_top_20(list);

    /**
     * free linked list memory
     */
    ll_clear(list, free);

    return 0;
}