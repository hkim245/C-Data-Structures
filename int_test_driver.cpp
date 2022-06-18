/**
 * @file int_test_driver.cpp
 * @author Dr. Schwesinger
 * CSC 237, Fall 2018, Assignment 1
 */

#include "Node.hpp"

/**
 * Tests the Node functions using int as the actual template parameter
 * @return the exit code
 */
int main() {
    // this sets cout to print booleans as strings
    std::cout << std::boolalpha;

    // create a list of the integers 1 to 10
    std::cout << "Create an empty list containing type int" << std::endl;
    Node<int>* head = nullptr;
    std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): " << length(head) << std::endl;
    std::cout << std::endl;

    // Test the push function
    std::cout << "Add the integers from 1 to 10 to the list" << std::endl;
    for (int i = 10; i > 0; i--) {
        head = insert(head, 1, i);
    }
    std::cout << "isEmpty(head): " << isEmpty(head) << std::endl;
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << std::endl;

    std::cout << "head = insert(head, 10, 42)" << std::endl;
    head = insert(head, 10, 42);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << "length(head): ";
    std::cout << length(head) << std::endl;
    std::cout << std::endl;

    // Test the contains function
    std::cout << "contains(head, 5): " << contains(head, 5) << std::endl;
    std::cout << "contains(head, 9000): " << contains(head, 9000) << std::endl;
    std::cout << std::endl;

    // Test the getElement function
    std::cout << "getElement(head, 10): ";
    std::cout << getElement(head, 10) << std::endl;
    std::cout << std::endl;

    // Test the getPosition function
    std::cout << "getPosition(head, 42): ";
    std::cout << getPosition(head, 42) << std::endl;
    std::cout << "getPosition(head, 20): ";
    std::cout << getPosition(head, 20) << std::endl;
    std::cout << std::endl;

    // Test the replace function
    std::cout << "replace(head, 7, 9000)" << std::endl;
    head = replace(head, 7, 9000);
    std::cout << "show(head)" << std::endl;
    show(head);
    std::cout << std::endl;

    // Test the remove function
    std::cout << "head = remove(head, 7)" << std::endl;
    head = remove(head, 7);
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

    return 0;
}
