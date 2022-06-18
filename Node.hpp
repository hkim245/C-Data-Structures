/**
 * @file Node.hpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 2
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

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
    // Error check
    if ((head == nullptr && position > 1) || position < 1) {
        throw (logic_error("Not a valid position in the linked list."));
    }
    // Base case
    if (position == 1) {
        Node<T>* newNode = new Node<T>();
        newNode->data = element;
        newNode->next = head;
        return newNode;
    }
    // Recursive case
    else {
        head->next = insert(head->next, position-1, element);
        return head;
    }
}

/**
 * Display a string representation of the list to standard out.
 * @param head the head of the linked list.
 */
template <class T>
void show(Node<T>* head) {
    // Base case
    if (head == nullptr) {
        cout << "NULL" << endl;
    }
    // Recursive case
    else {
        cout << head->data << " -> ";
        show(head->next);
    }
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
 * Gets the number of elements in the list using recursion.
 * @param head the head of the linked list.
 * @return The length of the entries currently in the list.
 */
template <class T>
int length(Node<T>* head) {
    if (head == nullptr) {         // Base case.
        return 0;
    }
    else {
        return 1+length(head->next);            // Recursive case.
    }
}

/**
 * Checks whether a element is contained in the list using recursion.
 * @param head the head of the linked list.
 * @param element the element to test.
 * @return True if the element is in the list, otherwise false.
 */
template <class T>
bool contains(Node<T>* head, T element) {
    if (head == nullptr) {          // First base case.
        return false;
    }
    else if (head->data == element) {           // Second base case.
        return true;
    }
    else {
        return contains(head->next, element);           // Recursive case.
    }
}


/**
 * Gets the element at the given position in the list using recursion.
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list
 * @param position the list position of the desired element.
 * @return the element at the desired list position.
 */
template <class T>
T getElement(Node<T>* head, int position) {
    if (position < 1 || position > length(head)) {                // Error checking.
        throw (logic_error("Not a valid position in the linked list."));
    }
    if (position == 1) {                 // First base case.       
        return head->data;
    }
    else {
        return getElement(head->next, position-1);             // Recursive case.
    }   
}

/**
 * Calls a helper function and returns a position in the linked list.
 * @param head the head of the linked list
 * @param element the desired element.
 * @return The integer position of the desired element if it occurs in the list,
 *         otherwise -1.
 */
template <class T>
int getPosition(Node<T>* head, T element) {
    int position = 1;       // Initialize an integer variable to count the position in the linked list.
    int result =  counter(head, element, position);           // Call the counter functino.
    return result;
}

/**
 * Gets the position of the first occurrence of the desired element using recursion.
 * @param head the head of the linked list
 * @param element the desired element.
 * @return The integer position of the desired element if it occurs in the list, 
 *         otherwise -1.
 */
template <class T>
int counter(Node<T>* head, T element, int position) {
    int result = -1;        // Initialize an integer variable result to default value of -1.
    if (head != nullptr) {           // If the node in the linked list does not point to null pointer, run this statement.
        if (head->data == element) {      // Base case.       
            result = position;
        }
        else {
            result = counter(head->next, element, position+1);         // Recursive case.
        }
   }
   return result;
}
       
/**
 * Replaces the element at the given position in the list using recursion.
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list.
 * @param position the list position of the element to replace.
 * @param element the replacement element
 * @return the head of the modified list.
 */
template <class T>
Node<T>* replace(Node<T>* head, int position, T element) {
    if (position < 1 || position > length(head)) {
        throw (logic_error("Not a valid position in the linked list."));           // Error checking.
    }
    if (position == 1) {                // Base case.
        head->data = element;
        return head;
    }
    else {
        head->next = replace(head->next, position-1, element);            // Recursive case.
        return head;
    }
}

/**
 * Removes the element at a given position from the list using recursion.
 * @pre 1 <= position <= length(head)
 * @param head the head of the linked list.
 * @param position the list position of the entry to remove.
 * @return the head of the modified list.
 */
template <class T>
Node<T>* remove(Node<T>* head, int position) {
    if (position > length(head) || position < 1) {
        throw (logic_error("Not a valid position in the linked list."));      // Error checking.
    }
    else if (head == nullptr) {
        cout << "Not a valid position in the linked list.";
    }
    if (position == 1) {                         // Base case.
        Node<T>* currentNode = head->next;
        head->next = nullptr;
        delete head;
        return currentNode;
    }
    else {
        head->next = remove(head->next, position-1);            // Recursive case.
        return head;
    }
}

#endif
