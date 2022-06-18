/**
 * @file string_test_driver.cpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 1
 */

#include <string>
#include <cstddef>
#include <iostream>
#include "Node.hpp"

void setBool();                                             // Function prototype setBool.
Node<std::string>* listString();                            // Function prototype listString.
Node<std::string>* testPush(Node<std::string>*);            // Function prototype testPush.
void testContains(Node<std::string>*);                      // Function prototype testContains.
void testGetElement(Node<std::string>*);                    // Function prototype testGetElement
void testGetPosition(Node<std::string>*);                   // Function prototype testGetPosition.
Node<std::string>* testReplace(Node<std::string>*);         // Function prototype testReplace.
void testRemove(Node<std::string>*);                        // Function prototype testRemove.

/**
 * Tests the Node functions using string as the actual template parameter
 * @return the exit code
 */
int main() {
    setBool();
    Node<std::string>* head = listString();       
    head = testPush(head);
    testContains(head);
    testGetElement(head);
    testGetPosition(head);
    head = testReplace(head);
    testRemove(head);

    return 0;
}
/**
 * Sets cout to print booleans as strings.
 */
void setBool() {
    std::cout << std::boolalpha;
}
/**
 * Create an empty list containing type string.
 * @return head the head of the linked list.
 */
Node<std::string>* listString() {
    std::cout << "Create an empty list containing type string" << std::endl;
    Node<std::string>* head = nullptr;        // head of the linked list is a null pointer
    std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;          // Check if the linked list is empty.
    std::cout << "show(head)" << std::endl;                // Display the linked list.
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;          // The length of the linked list.
    std::cout << std::endl;
    return head;
}
/**
 * Test the push function.
 * @param head the head of the linked list.
 * @return head the head of the linked list.
 */
Node<std::string>* testPush(Node<std::string>* head) {
    std::cout << "Add the string of integers from 1 to 5 to the list" << std::endl;
    head = insert(head, 1, std::string("one"));         // Insert the string "one" at the first position in the linked list.
	
	
	std::cout << head << std::endl;
	
	
    head = insert(head, 2, std::string("two"));    
    head = insert(head, 3, std::string("three"));
    head = insert(head, 4, std::string("four"));
    head = insert(head, 5, std::string("five"));

    std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << std::endl;

    std::cout << "head = insert(head, 3, std::string(\"Bob\"))" <<std::endl;
    head = insert(head, 3, std::string("Bob"));
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): ";
    std::cout << length(head) << std::endl;
    std::cout << std::endl;
    return head;
}
/**
 * Test the contains function.
 * @param head the head of the linked list.
 */
void testContains(Node<std::string>* head) {
    std::cout << "contains(head, std::string(\"one\")): "            // Check if the linked list contains the string "one".
    << contains(head, std::string("one")) << std::endl;   
    std::cout << "contains(head, std::string(\"Alice\")): " 
    << contains(head, std::string("Alice")) << std::endl;
    std::cout << std::endl;
}
/**
 * Test the getElement function.
 * @param head the head of the linked list
 */
void testGetElement(Node<std::string>* head) {
    std::cout << "getElement(head, 3): ";                   // Get the element at the third position in the linked list.
    std::cout << getElement(head, 3) << std::endl;
    std::cout << std::endl;
}
/**
 * Test the getPosition function
 * @param head the head of the linked list.
 */
void testGetPosition(Node<std::string>* head) {
    std::cout << "getPosition(head, std::string(\"five\")): ";            // Get the position of the element of string "five".
    std::cout << getPosition(head, std::string("five")) << std::endl;
    std::cout << "getPosition(head, std::string(\"Alice\")): ";
    std::cout << getPosition(head, std::string("Alice")) << std::endl;
    std::cout << std::endl;
}
/**
 * Test the replace function
 * @param head the head of the linked list
 * @return head the head of the linked list
 */
Node<std::string>* testReplace(Node<std::string>* head) {
    std::cout << "replace(head, 3, std::string(\"Eve\")) " << std::endl;            // Replace the element at the third position in the linked list with string "Eve".
    head = replace(head, 3, std::string("Eve"));
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << std::endl;
    return head;
}
/**
 * Test the remove function
 * @param head the head of the linked list.
 */
void testRemove(Node<std::string>* head) {
    std::cout << "head = remove(head, 3)" << std::endl;                // Remove the third element in the linked list.
    head = remove(head, 3);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
 
    std::cout << "head = remove(head, 1)" << std::endl;
    head = remove(head, 1);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;
}
