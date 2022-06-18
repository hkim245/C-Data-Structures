/**
 * @file Node.hpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 1
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>

/**
 * @class Node
 * @brief A node in a linked list
 */
template <class T>
struct Node {
    /** The data element **/
    T data;
    /** A pointer to the next Node **/
    Node<T>* next;
};


/**
 * Insert an element into a linked list at a given position
 * @pre The position is within the bound of the list, that is,
 *      1 <= position <= length(head)+1
 * @param head the head of the linked list.
 * @param position the list position at which to insert element.
 * @param element the element to insert into the list.
 * @return the head of the modified list
 */
template <class T>
Node<T>* insert(Node<T>* head, int position, T element) {
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node<T>* previousNode = head;
        for (int p = 1; p < position-1; p++) {
            previousNode = previousNode->next;
        }
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    return head;
}

/**
 * Display a string representation of the list to standard out.
 * @param head the head of the linked list.
 */
template <class T>
void show(Node<T>* head) {
    Node<T>* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << currentNode->data;
        std::cout << " -> ";
        currentNode = currentNode->next;
    }
    std::cout << "NULL" << std::endl;
}

/**
 * Checks whether the list is empty.
 * @param head the head of the linked list.
 * @return True if the list is empty, otherwise false.
 */
template <class T>
bool isEmpty(Node<T>* head) {
    return head == nullptr;
}

/**
 * Returns the number of elements in a linked list.
 * @param head the head of the linked list.
 * @return length the length of the linked list.
 */
template <class T>
int length(Node<T>* head) {
    if (isEmpty(head)) {       // Check to see if the linked list is empty.
        return 0;
    }
    Node<T>* currentNode = head;
    int length = 0;                     
    while (currentNode != nullptr) {    
        length++;         // Increment the length for each node pointing to an element in the linked list.
        currentNode = currentNode->next;
    }
    return length;
}

/**
 * Returns a boolean indicating whether the parameter element is contained
 * within the linked list.
 * @param head the head of the linked list.
 * @param element the desired element in the linked list.
 * @return boolean a boolean indicating whether the parameter element is contained.
 */
template <class T>
bool contains(Node<T>* head, T element) {
    if (isEmpty(head)) {        // Check to see if the linked list is empty.
         return false;
    }
    Node<T>* currentNode = head;
    while (currentNode != nullptr) {         // While loop to go through the entire linked list until the element is found.
        if (currentNode->data == element) {
            return true;
        }          
        currentNode = currentNode->next;   
    } 
    return false;
}

/**
 * Returns the element at the desired position of the list.
 * @param head the head of the linked list.
 * @param position the position of the element in the list.
 * @return the element at the desired position of the list.
 */
template <class T>
T getElement(Node<T>* head, int position) {
    if (isEmpty(head)) {       // Check to see if the linked list is empty.
        std::cout << "Not a valid position in the list.";
        return 0;
    }
    if (position > length(head) || position < 1) {        // Check to see if user entered valid position in the linked list.
        std::cout << "Not a valid position in the list.";
        return 0;
    }
    Node<T>* currentNode = head;
    for (int p=1; p < position; p++) {       // For loop to get to the desired position in the linked list.
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

/**
 * Returns the position of the first instanace of the element passed 
 * in as a parameter. If the element is not present in the list,
 * then return -1.
 * @param head the head of the linked list.
 * @param element the element contained in the instance
 * @return the position of the element in the list.
 */
template <class T>
int getPosition(Node<T>* head, T element) {
    if (isEmpty(head)) {      // Check to see if the linked list is empty.
        return -1;
    }
    Node<T>* currentNode = head;
    int position = 1;
    while (currentNode != nullptr) {       // While loop to go through the entire linked list.     
        if (currentNode->data == element) {        // Run this statement if element is found in the linked list.
        return position;
        }
        ++position;
        currentNode = currentNode->next;
    }
    return -1;
}

/**
 * Replaces the element at the desired position of the list and 
 * returns the head of the modified list.
 * @param head the head of the linked list.
 * @param position the desired position of the list
 * @param element of an instance in the list
 * @return head of the modified list.
 */
template <class T>
Node<T>* replace(Node<T>* head, int position, T element) {
    if (isEmpty(head)) {      // Check to see if the linked list is empty.
        std:: cout << "Not a valid position in the list.";
        return head;
    } 
    if (position > length(head) || position < 1) {       // Check to see if user entered valid position in the linked list.
        std:: cout << "Not a valid position in the list.";
        return head;
    }
    Node<T>* currentNode = head;
    for (int p=1; p < position; p++) {           // For loop to get to the desired position in the linked list.
        currentNode = currentNode->next; 
    }
    currentNode->data = element;       
    return head;
}

/**
 * Removes the Node at the desired position of the list and returns 
 * the head of the modified list.
 * @param head the head of the linked list.
 * @param position the desired position of the list.
 * @return the head of the modified list.
 */
template <class T>
Node<T>* remove(Node<T>* head, int position) {
    if (isEmpty(head)) {    // Check to see if linked list is empty.
        std:: cout << "Not a valid position in the list.";
        return head;
    }
    if (position > length(head) || position < 1) {      // Check to see if user entered valid position in the linked list.
        std:: cout << "Not a valid position in the list.";
        return head;
    }
    Node<T>* previousNode = head;
    Node<T>* currentNode = previousNode;
    if (position == 1) {        // Run this statement if position is equal to 1.
        head = previousNode->next;
        previousNode->next = nullptr;
        delete previousNode;       // Delete the object in the heap and return the memory.
        return head;
    }
    for (int p=1; p < position; p++) {       // For loop to get to the desired position in the linked list.
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode->next == nullptr)       // Run this statement if the node is the last node in the linked list.
    {
        previousNode->next = nullptr;
        delete currentNode;
        return head;
    }
    previousNode->next = currentNode->next;
    currentNode->next = nullptr;
    delete currentNode;  
    return head;
}

#endif
