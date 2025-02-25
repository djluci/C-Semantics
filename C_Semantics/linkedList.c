/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedList.h"

/**
 * Creates a new empty linked list:
 * 1. allocating memory for the LinkedList 
 * 2. initializing the head pointer to NULL
 * 3. returning the new list
 */
LinkedList *ll_create() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/**
 * Adds a new node to the front of the list
 * 1. Create a new Node
 * 2. Set data field of Node to the given data
 * 3. Point new node's next to current head of the list
 * 4. Update list's head to point to the new node
 */
void ll_push(LinkedList *l, void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
}

/**
 * Removes the node at the front of the list and returns the associated data
 * 1. if the list is empty then return NULL
 * 2. Store pointer to first node
 * 3. update list head to the next node
 * 4. Retrieve data from the removed node
 * 5. free the node and return the data
 */
void *ll_pop(LinkedList *l) {
    if (l->head == NULL) {
        return NULL;
    }
    Node *temp_node = l->head;
    void *data = temp_node->data;
    l->head = l->head->next;
    free(temp_node);

    return data;
}

/**
 * Adds a node to the end of the list, storing given data in the node
 * 1. Create a new node
 * 2. Set data of the node to the given data
 * 3. If list is empty then set head to the new node
 * 4. Else if the list is NOT empty then traverse to the last node and link the last node to the new node
 */
void ll_append(LinkedList *l, void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL; // there is no next node

    if (l->head == NULL) {
        l->head = new_node;
    }
    else {
        Node *current = l->head;
        while (current->next != NULL) {
            current = current->next; // traverses to the last node until there is no next node
        }
        current->next = new_node; // links last node to new node
    }
}

/**
 * Remove the first node where the data matches the target:
 * 1. Traverse list and use compfunc to compare each node's data with target
 * 2. If match is found then we update the previous node's next to skip current node
 *    Next, store data free the node and return the data
 * 3. If a match is not found then return NULL
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)) {
    Node *current = l->head;
    Node *previous = NULL;

    while (current != NULL) {
        if(compfunc(current->data, target) == 0) {
            if(previous == NULL) {
                l->head = current->next;
            }
            else {
                previous->next = current->next; // update previous node's next to skip current node
            }
            void *data = current->data; // store data
            free(current);
            return data;
        }
        previous = current;
        current = current ->next;
    }
    return NULL;
}

/**
 * Find and return the data of the first node that matches the target:
 * 1. Traverse the list using the compfunc to compare each node's data with target
 * 2. if a match is found, return the data
 * 3. if no match is found, return NULL
 */

void *ll_find(LinkedList *l, void *target, int(*compfunc)(void *, void *)) {
    Node *current = l->head;

    while (current != NULL) {
        if(compfunc(current->data, target) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * Return the number of nodes in the list:
 * 1. intialize a counter to 0
 * 2. traverse list and increment counter for each node
 * 3. return counter value
 */
int ll_size(LinkedList *l) {
    int counter = 0;
    Node *current = l->head;
    while (current != NULL) {
        counter++;
        current = current->next;
    }
    return counter;
}

/**
 * Removes all nodes from the list and frees their associated data:
 * 1. Traverse list
 * 2. Use freefunc to free data in each node
 * 3. free node itself
 * 4. set list's head to NULL
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *)) {
    Node *current = l->head;
    while (current != NULL) {
        Node *next = current->next;
        freefunc(current->data); // free node of each node
        free(current); // frees current node
        current = next;
    }
    l->head = NULL;
}

/**
 * Apply a function to the data of each node in the list:
 * 1. traverse the list
 * 2. for each node apply mapfunc to the data
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *)) {
    Node *current = l->head;
    while (current != NULL) {
        mapfunc(current->data);
        current = current->next;
    }
}

/**
 * String to lowercase:
 * 1. case-insensitivity for all words
 */
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/**
 * Remove punctuation from word:
 * 1. remove non-alphanumeric characters
 * 2. null-terminate modified string
 */
void remove_punctuation(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

/**
 * Push word or increment(if already exists):
 * 1. if words exist we increment its frequency
 * 2. if word doesnt exist then we add a new node to list w/ frequency of 1.
 */
void ll_push_or_increment(LinkedList *l, const char *word) {
    Node *current = l->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return;
        }
        current = current->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->frequency = 1;
    new_node->next = l->head;
    l->head = new_node;
}

/**
 * sorts linkedList by frequency(descending)
 * uses a simple sorting algorithm
 * 1. use nesrtred loop for selection sort on linkedList by frequency
 * 2. swap data between nodes i and j if j is higher frequency
 */
void ll_sort(LinkedList *l) {
    if (l->head == NULL) return;

    Node *i, *j;
    for (i = l->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next){
            if (j->frequency > i->frequency) {
                int temp_freq = i->frequency;
                char *temp_word = i->word;
                i->frequency = j->frequency;
                i->word = j->word;
                j->frequency = temp_freq;
                j->word = temp_word;
            }
        }
    }
}

/**
 * Prints top 20 words in list
 * 1. traverse list
 * 2. print first 20 nodes w/ word and frequency
 */
void ll_print_top_20(LinkedList *l) {
    Node *current = l->head;
    int count = 0;
    while(current != NULL && count < 20) {
        printf("%s %d\n", current->word, current->frequency);
        current = current->next;
        count++;
    }
}