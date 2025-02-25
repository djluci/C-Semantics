/**
 * Duilio Lucio
 * 10/06/2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/**
 * Creates a Node Class:
 * 1. void pointer to store generic data
 * 2. a pointer to the next node
 */
template <typename T>
class Node {
public:
    T data; // generic data
    Node *next; // pointer to the next node

    Node (T value) : data(value), next(nullptr){} // constructor that initializes a new node
};

/**
 * Create a LinkedList class that stores:
 * 1. head pointer
 * 2. methods to manipulate list(push, pop, etc)
 */
template <typename T>
class LinkedList {
private:
    Node<T> *head; // head pointer that points to the head of the list.

public: 
   /**
    * Constructor & Destructor:
    * 1. for constructor, initialize the head pointer to nullptr
    * 2. for destructor, use clear() to free all memory when object is destroyed
    */
    LinkedList() : head(nullptr){} // constructor
    ~LinkedList() { clear(); } // destructor

    /**
     * Push function :
     * 1. add new node to the front of the list
     * 2. create a new node, set its data and link to current head
     * 3. update head pointer to the new node
     */
    void push(T value) {
        Node<T> *new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;
    }

    /**
     * Pop function:
     * 1. Remove & return data of the first node
     * 2. if list is empty then return nullptr
     * 3. if not then update the head to the next node and free the previous head
     */
    T pop() {
        if (head == nullptr) throw std::out_of_range("List is empty");

        Node<T> *temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }

    /**
     * Append Function:
     * 1. Add a new node to the end of the list
     * 2. if the list is empty then the new node becomes the head.
     * 3. Otherwise, traverse list to the last node & add the new node 
     */
    void append(T value) {
        Node<T> *new_node = new Node<T>(value);
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node<T> *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    /**
     * Remove Function:
     * 1. Traverse list & remove the first node that matches the target data using a comparison function
     * 2. if a match is found then unlike node and free the memory
     * 3. return the data if the node was removed, but if it wasnt then return nullptr
     */
    bool remove(T target) {
        Node<T> *current = head;
        Node<T> *previous = nullptr;

        while (current != nullptr) {
            if (current->data == target) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    /**
     * Find Function:
     * 1. traverse list and return the data of the first matching node
     * 2. comparison function to check for a match
     * 3. if no match is found then return nullptr.
     */
    bool find(T target) const{
        Node<T> *current = head;
        while (current != nullptr) {
            if (current->data == target) return true;
            current = current->next;
        }
        return false;
    }

    /**
     * Size function:
     * 1. traverse the list and count the number of nodes
     * 2. return total count
     */
    int size() const {
        int count = 0;
        Node<T> *current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    /**
     * Clear function:
     * 1. traverse the list and delete all nodes
     * 2. use function pointer to release data from each node
     */
    void clear() {
        Node<T> *current = head;

        while(current != nullptr) {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    /**
     * Map Function:
     * 1. traverse the list and apply a function to each node's data
     */
    void map(void (*func)(T &)) {
        Node<T> *current = head;
        while (current != nullptr) {
            func(current->data);
            current = current->next;
        }
    }

    /**
     * Print Function:
     * 1. traverse the list and print every current data
     */
    void print() const{
        Node<T> *current = head;
        while(current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif