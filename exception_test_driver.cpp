/**
 * @file exception_test_driver.cpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 2
 */

#include "Node.hpp"
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

void setBool();                              // Function prototypes.
Node<int>* testInsert();                     
void testGetElement(Node<int>*);             
Node<int>* testReplace(Node<int>*);          
void testRemove(Node<int>*);               

/**
 * Tests the error cases of the Node functions that rely on position.
 * @return the exit code
 */
int main() {
    // The Node functions test invalid positions.
    setBool();
    Node<int>* head = testInsert();
    testGetElement(head);
    head = testReplace(head);
    testRemove(head);
    
    return 0;
}

/**
 * Sets cout to print booleans as strings.
 */
void setBool() {
    cout << boolalpha;
}

/**
 * Test the insert function.
 * @param head the head of the linked list.
 * @return head the head of the linked list.
 */    
Node<int>* testInsert() {
    Node<int>* head = nullptr;             // Head of the linked list is a null pointer.    
    cout << "Add the integers from 1 to 5 in the list." << endl;
    cout << "insert(head, 10, 1): ";
    try {                                     // Try catch statement.
        head = insert(head, 10, 1);                 
    }               
    catch (logic_error e) {                    // Catch the logic error.
       cout << e.what() << endl;
    }
    for (int i = 1; i < 6; i++) {
        cout << "insert(head, " << i << ", " << i << ")" << endl;
        head = insert(head, i, i);
    }
    cout << "insert(head, -1, 5): ";
    try {
        head = insert(head, -1, 5);
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }
    cout << "show(head)" << endl;
    show(head);                       // Display the linked list.
    cout << endl;
    return head;
}

/** 
 * Test the getElement function.
 * @param head the head of the linked list.
 * @return head the head of the linked list.
 */
void testGetElement(Node<int>* head) {
    cout << "getElement(head, 15): ";                  // Retrieve the element at the tenth position of the linked list.
    try {              // Try catch statement.            
        cout << getElement(head, 15) << endl;            
    }
    catch (logic_error e) {             // Catch the logic error.
        cout << e.what() << endl;
    }
    cout << "getElement(head, -1): ";
    try {
        cout << getElement(head, -1) << endl;
    }
    catch (logic_error e) {
        cout << e.what()  << endl;
    }
    cout << "getElement(head, 5): ";
    cout << getElement(head, 5) << endl;
    cout << "show(head)" << endl;
    show(head);
    cout  << endl;
}

/**
 * Test the replace function.
 * @param head the head of the linked list.
 * @return head the head of the linked list.
 */
Node<int>* testReplace(Node<int>* head) {
    cout << "replace(head, 100, 80): ";             // Replace the element at position 100 with integer 80.
    try {             // Try catch statement.
        head = replace(head, 8, 100); 
    }
    catch (logic_error e) {            // Catch the logic error.
        cout << e.what() << endl;
    }
    cout << "replace(head, -1, 100): ";
    try {
        head = replace(head, -1, 100); 
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }
    cout << "replace(head, 2, 12)";
    head = replace(head, 2, 12);
    cout << endl << "show(head)" << endl; 
    show(head); 
    cout << endl;
    return head;
}

/**
 * Test the remove function.
 * @param head the head of the linked list.
 * @return head the head of the linked list.
 */
void testRemove(Node<int>* head) {
    cout << "remove(head, -1): ";                   // Remove the element at the negative one position in the linked list.
    try {
        head = remove(head, -1); 
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }  
    cout << "remove(head, 100): ";
    try {
        head = remove(head, 100); 
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }
    cout << "remove(head, 1)";
    head = remove(head, 1);
    cout << endl << "show(head)" << endl; 
    show(head); 
}   
