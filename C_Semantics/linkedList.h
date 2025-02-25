/**
 * Duilio Lucio
 * 10/06/2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * Node structure that holds void* pointer that stores generic data 
 * and next pointer to link to the next node
 */
typedef struct Node {
    void *data;
    char *word;
    int frequency;
    struct Node *next;
} Node;

/**
 * LinkedList structure that has a pointer that points to the head of the list.
 * 
 */
typedef struct LinkedList{
    Node *head; 
}LinkedList;

// Function prototypes
LinkedList *ll_create();
void ll_push(LinkedList *l, void *data);
void *ll_pop(LinkedList *l);
void ll_append(LinkedList *l, void *data);
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *));
int ll_size(LinkedList *l);
void ll_clear(LinkedList *l, void (*freefunc)(void *));
void ll_map(LinkedList *l, void (*mapfunc)(void *));
void to_lowercase(char *str);
void remove_punctuation(char *str);
void ll_push_or_increment(LinkedList *l, const char *word);
void ll_sort(LinkedList *l);
void ll_print_top_20(LinkedList *l);

#endif
