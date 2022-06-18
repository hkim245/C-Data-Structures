/**
 * @file test_driver.cpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 6
 */

#include <iostream>
#include <vector>

#include "CompleteBinaryTree.h"

void displayHeight(CompleteBinaryTree<int>&);                     // Function prototypes.
void add(CompleteBinaryTree<int>&);
void displayCapacity(CompleteBinaryTree<int>&);
void remove(CompleteBinaryTree<int>&);
void preorderTraverse(CompleteBinaryTree<int>&, vector<int>&);
void inorderTraverse(CompleteBinaryTree<int>&, vector<int>&);
void postorderTraverse(CompleteBinaryTree<int>&, vector<int>&);
void testCopyConstructor();
void testAssignmentOperator();

using namespace std;

/**
 * Call the functions and initialize objects.
 * @return 0 exit the program.
 */
int main() {
    CompleteBinaryTree<int> cbt;
    vector<int> result;

    displayHeight(cbt);
    add(cbt);
    displayHeight(cbt);
    displayCapacity(cbt);
    remove(cbt);
    preorderTraverse(cbt, result);
    inorderTraverse(cbt, result);
    postorderTraverse(cbt, result);
    testCopyConstructor();
    testAssignmentOperator();

    return 0; 
}

/**
 * Display the height of the complete binary tree.
 * @param cbt the complete binary tree.
 */
void displayHeight(CompleteBinaryTree<int>& cbt) {
    int height = cbt.getHeight();
    cout << "height: " << height << endl;
}

/**
 * Add elements to the complete binary tree.
 * @param cbt the complete binary tree.
 */
void add(CompleteBinaryTree<int>& cbt) {
    for (int x = 0; x < 17; x++) {
        if (cbt.add(x)) {

        }
        else {
            cout << "The node " << x << " was not successfully added." << endl;
        }      
    }
}

/** 
 * Display the capacity of the complete binary tree.
 * @param cbt the complete binary tree.
 */
void displayCapacity(CompleteBinaryTree<int>& cbt) {
    int capacity = cbt.getCapacity();
    cout << "capacity: " << capacity << endl;
}

/**
 * Remove the element 0 from the complete binary tree.
 * @param cbt the complete binary tree.
 */
void remove(CompleteBinaryTree<int>& cbt) {
    if (cbt.remove(0)) {

    }
    else {
        cout << "The node 0 was not successfully removed." << endl;
    }
}

/**
 * Traverse the complete binary tree in preorder and display the traversal.
 * @param cbt the complete binary tree
 * @param result the vector that contains the traversal.
 */
void preorderTraverse(CompleteBinaryTree<int>& cbt, vector<int>& result) {
    result  = cbt.preorderTraverse();
    int size = result.size();
    cout << "Preorder Traversal: ";
    for (int x = 0; x < size; x++) {
        cout << result[x] << ", ";
    }
    cout << endl;
}

/**
 * Traverse the complete binary tree in inorder and display the traversal.
 * @param cbt the complete binary tree.
 * @param result the vector that contains the traversal.
 */
void inorderTraverse(CompleteBinaryTree<int>& cbt, vector<int>& result) {
    result = cbt.inorderTraverse();
    int size = result.size();
    cout << "Inorder Traversal: ";
    for (int x = 0; x < size; x++) {
        cout << result[x] << ", ";
    }
    cout << endl;
}

/**
 * Traverse the complete binary tree in postorder and display the traversal.
 * @param cbt the complete binary tree.
 * @param result the vector that contains the traversal.
 */
void postorderTraverse(CompleteBinaryTree<int>& cbt, vector<int>& result) {
    result = cbt.postorderTraverse();
    int size = result.size();
    cout << "Postorder Traversal: ";
    for (int x = 0; x < size; x++) {
        cout << result[x] << ", ";
    }
    cout << endl;
}

/**
 * Test the copy constructor of the complete binary tree.
 */
void testCopyConstructor() {
    CompleteBinaryTree<int> cbt1;
	
    for (int x = 0; x < 24; x++) {
        if (cbt1.add(x)) {

	}
	else {
	cout << "The node " << x << " was not successfully added." << endl;
	}
    }
	
    CompleteBinaryTree<int> copy(cbt1);							// Use the copy constructor.
	
    int itemCount = cbt1.getNumberOfNodes();
    int height = cbt1.getHeight();
    int capacity = cbt1.getCapacity();
	
    cout << endl;
    cout << "Copy Constructor Test" << endl;							// For the complete binary trees, display the number of items, height, capacity, and check if it is empty.
    cout << "-------------------------" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;

    for (int x = 0; x < 24; x++) {						// Add 24 integers to cbt1.
        if (cbt1.add(x)) {
			
	}
	else {
	    cout << "The node " << x << " was not successfully added." << endl;
	}
    }
	
    itemCount = cbt1.getNumberOfNodes();
    height = cbt1.getHeight();
    capacity = cbt1.getCapacity();
	
    cout << "ADD TO ORIGINAL" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
	
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;
	
    cbt1.clear();				// Delete all of the items in cbt1.
	
    itemCount = cbt1.getNumberOfNodes();
    height = cbt1.getHeight();
    capacity = cbt1.getCapacity();
	
    cout << "REMOVE FROM ORIGINAL" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
	
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;
}

/**
 * Test the assignment operator of the complete binary tree.
 */
void testAssignmentOperator() {
    CompleteBinaryTree<int> cbt1;
	
    for (int x = 0; x < 24; x++) {
	if (cbt1.add(x)) {

  	} 
	else {
	    cout << "The node " << x << " was not successfully added." << endl;
	}
    }
	
    CompleteBinaryTree<int> copy;						
    copy = cbt1;									// Use the assignment operator.
	
    int itemCount = cbt1.getNumberOfNodes();
    int height = cbt1.getHeight();
    int capacity = cbt1.getCapacity();
	
    cout << endl;
    cout << "Assignment Operator Test" << endl;							// For the complete binary trees, display the number of items, height, capacity, and check if it is empty.
    cout << "-------------------------" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
	
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;

    for (int x = 0; x < 24; x++) {						// Add 24 integers to cbt1.
        if (cbt1.add(x)) {
			
	}
	else {
	    cout << "The node " << x << " was not successfully added." << endl;
	}
    }
	
    itemCount = cbt1.getNumberOfNodes();
    height = cbt1.getHeight();
    capacity = cbt1.getCapacity();
    cout << "ADD TO ORIGINAL" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
	
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;
	
    cbt1.clear();						// Delete all of the items in cbt1.
	
    itemCount = cbt1.getNumberOfNodes();
    height = cbt1.getHeight();
    capacity = cbt1.getCapacity();
	
    cout << "REMOVE FROM ORIGINAL" << endl;
    cout << "ORIGINAL: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << cbt1.isEmpty() << endl;
	
    itemCount = copy.getNumberOfNodes();
    height = copy.getHeight();
    capacity = copy.getCapacity();
	
    cout << "COPY: " << "itemCount: " << itemCount << " height: " << height << " capacity: ";
    cout << capacity << " empty: " << copy.isEmpty() << endl;
}
