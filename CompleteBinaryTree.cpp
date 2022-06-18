/**
 * @file CompleteBinaryTree.cpp
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 6
 */

#include "CompleteBinaryTree.h"

#include <vector>
#include <stack>

using namespace std;

/**
 * Default constructor - Initialize default values for all data members.
 */
template<class ItemType>
CompleteBinaryTree<ItemType>::CompleteBinaryTree(): capacity(DEFAULT_CAPACITY), itemCount(0) {
    items = new ItemType[capacity + 1];
    for (int x = 1; x < capacity + 1; x++) {                 // For loop through the complete binary tree.
        items[x] = -1;       // Initialize all items in the array to -1.
    }
}

/**
 * Destructor - Deallocate the memory stored in the heap.
 */
template<class ItemType>
CompleteBinaryTree<ItemType>::~CompleteBinaryTree() {
    delete[] items;
}

/**
 * Copy Constructor - Copy an object's value to another object.
 * @param other the other complete binary tree to be copied.
 */
template<class ItemType>
CompleteBinaryTree<ItemType>::CompleteBinaryTree(const CompleteBinaryTree & other) {
    items = new ItemType[other.capacity + 1];            // Double the size of the array if the capacity is full.
    capacity = other.capacity;
    itemCount = other.itemCount;
    for (int x = 1; x <= other.itemCount; x++) {                  // For loop through the complete binary tree.
        items[x] = other.items[x];
    }
}

/**
 * Overloading Assignment Operator - Set one object equal to another object.
 * @param other rvalue of the assignment operator.
 */
template<class ItemType>
CompleteBinaryTree<ItemType>& CompleteBinaryTree<ItemType>::operator=(const CompleteBinaryTree & other) {
    if (this == &other) {               
        return *this;
    }
    delete[] items;                     // Deallocate the memory stored in the heap.
    items = new ItemType[other.capacity + 1];					// Create a new array of the other array's capacity.
    capacity = other.capacity;
    itemCount = other.itemCount;
    for (int x = 1; x <= other.itemCount; x++) {                // For loop through the complete binary tree.
        items[x] = other.items[x];
    }
    return *this;
}

/**
 * Check if the complete binary tree is empty.
 * @return boolean true if the complete binary tree is empty,
 * otherwise false.
 */
template<class ItemType>
bool CompleteBinaryTree<ItemType>::isEmpty() {
    return itemCount == 0;
}

/**
 * Get the height of the complete binary tree.
 * @return height the height of the complete binary tree.
 */
template<class ItemType>
int CompleteBinaryTree<ItemType>::getHeight() {
    int numItems = itemCount;
    int height = 0;
    if (isEmpty()) {
        return height;
    }
    height++;
    while (numItems != 1) {          
        numItems /= 2;          // Levels of a complete binary tree can be calculated by 2 to the h - 1 many nodes.
        height++;
    }
    return height; 
}

/**
 * Get the number of items in the complete binary tree.
 * @return the number of items in the complete binary tree.
 */
template<class ItemType>
int CompleteBinaryTree<ItemType>::getNumberOfNodes() {
    return itemCount; 
}

/**
 * Get the total capacity in the complete binary tree.
 * @return capacity the total capacity in the complete binary tree.
 */
template<class ItemType>
int CompleteBinaryTree<ItemType>::getCapacity() {
    return capacity;
}

/**
 * Adds a new node containing the given data to this binary tree. The node
 * is added to maintain the complete property of the binary tree. That is,
 * the binary tree is filled in left to right, top to bottom. If adding the
 * new node exceeds the capacity of the backing array, then the capacity of
 * the backing array is doubled.
 * @param newData the data for the new node.
 * @post the binary tree contains a new node and the complete property is
 * not violated.
 * @return true if the addition was successful, otherwise false.
 */
template<class ItemType>
bool CompleteBinaryTree<ItemType>::add(const ItemType& newData) {
    if (itemCount + 1 > capacity) {
        ItemType* oldArray = items;       
        items = new ItemType[2 * capacity];            // Double the size of the array if the capacity is full.
        for (int x = 1; x <= itemCount; x++) {                   // For loop through the complete binary tree to copy the old array values into the new array.
            items[x] = oldArray[x];
        }
        delete[] oldArray;                         // Deallocate the memory stored in the heap.
        capacity *= 2;
        for (int x = itemCount + 1; x < capacity + 1; x++) {                   // For loop through the complete binary tree from the first empty index to the rest of the array to insert a default value of -1 in each of the indices.
            items[x] = -1;
        }
    }
    for (int x = 1; x < capacity + 1; x++) {                     // For loop through the complete binary tree to insert a new item in the tree.
        if (items[x] == -1) {
            items[x] = newData;
            itemCount++;
            return true;
        }
    }
    return false;
}

/**
 * Removes the node containing the given data item from this binary tree.
 * To maintain the complete property, the rightmost node at the lowest
 * level is placed at the location of the removed node. If the removal of
 * the node reduces the number of nodes to less than the current capacity
 * divided by four and greater than the default capacity, then the capacity
 * of the backing array is halved.
 * @param data the data value to remove form the binary tree.
 * @return true if the removal was successful, otherwise false.
 */
template<class ItemType>
bool CompleteBinaryTree<ItemType>::remove(const ItemType& data) {
    if (isEmpty()) {                       // Check if the complete binary tree is empty.
        return false;
    }
    int removeIndex = -1;
    for (int x = 1; x < capacity + 1; x++) {                      // For loop through the complete binary tree to check if the tree contains the item.
        if (items[x] == data) {
            removeIndex = x;
            if (itemCount - 1 < capacity / 4 && itemCount - 1 > DEFAULT_CAPACITY) {
                capacity /= 2;
                break;
            }
            break;
        }
    }
    if (removeIndex != -1) {
        for (int x = 1; x < capacity + 1; x++) {                    
            if (items[x + 1] == -1 || x == capacity) {
                items[removeIndex] = items[x];
                items[x] = -1;
                itemCount--;
                return true;
            }
        }
    }
    return false;
}

/**
 * Removes all the nodes from this binary tree. If the capacity of the
 * backing array is greater than the default capacity, then the capacity of
 * the backing array is changed to the default capacity.
 */
template<class ItemType>
void CompleteBinaryTree<ItemType>::clear() {
    if (capacity > DEFAULT_CAPACITY) {
        capacity = DEFAULT_CAPACITY;
    }
    for (int x = 1; x <= itemCount; x++) {                // For loop through the complete binary tree to give the items in the tree a default value of -1.
        items[x] = -1;
    } 
    itemCount = 0;
}

/**
 * Check if the complete binary tree contains a certain item.
 * @param anEntry the item to check in the complete binary tree.
 * @return true if the complete binary tree contains the item,
 * otherwise false.
 */
template<class ItemType>
bool CompleteBinaryTree<ItemType>::contains(const ItemType& anEntry) {
    for (int x = 1; x <= itemCount; x++) {                     // For loop through the complete binary tree to check if the tree contains the item.
        if (items[x] == anEntry) {
            return true;
        }
    }
    return false;
}

/**
 * Traverse the complete binary tree in preorder.
 * @return result a vector of the items in the order of the traversal.
 */    
template<class ItemType>
vector<ItemType> CompleteBinaryTree<ItemType>::preorderTraverse() {
    vector<ItemType> result;					// Create a vector.
    if (isEmpty()) {
        return result;
    }
    stack<ItemType> traversal;				 		// Create a stack.
	
    int root = 1;
	
    traversal.push(root);				// Push the root of the tree into the stack.
    while (!traversal.empty()) {
        root = traversal.top();
        result.push_back(items[root]);				// Push the node into the vector.
        traversal.pop();
	if (root * 2 + 1 <= itemCount) {				// Push the right child of this node into the stack. 
            traversal.push(root * 2 + 1);
	}
	if (root * 2 <= itemCount) {					// Push the left child of this node into the stack.
            traversal.push(root * 2);
	}
    }
	
    return result;
}

/**
 * Traverse the complete binary tree in inorder.
 * @return result a vector of the items in the order of the traversal.
 */
template<class ItemType>
vector<ItemType> CompleteBinaryTree<ItemType>::inorderTraverse() {
    vector<ItemType> result;				// Create a vector.
    if (isEmpty()) {	
        return result;
    }
    stack<ItemType> traversal;					// Create a stack.
	
    int root = 1;
    int right = 3;
	
    traversal.push(root);					// Push the root of the tree into the stack.
    root = root * 2;
    while (!traversal.empty()) {
        if (root <= itemCount) {
	    traversal.push(root);					// Push the left child of this node into the stack.
	    root = root * 2;
	}
        else {
	    if (!traversal.empty()) {
	        root = traversal.top();
		traversal.pop();
		if (root == right && traversal.empty()) {					// Once the traversal has finished, break the loop.
		    break;
		}
	        result.push_back(items[root]);
		root = root * 2 + 1;							// Push the right child of this nodeinto the stack.
	    }
	    if (traversal.empty() && root <= itemCount) {					// Push the root of the right subtree into the stack.
		traversal.push(root);
	    }
        }
    }

    return result; 
}

/**
 * Traverse the complete binary tree in postorder.
 * @return result a vector of the items in the order of the traversal.
 */
template<class ItemType>
vector<ItemType> CompleteBinaryTree<ItemType>::postorderTraverse() {
    vector<ItemType> result;					// Create a vector.
    if (isEmpty()) {
        return result;
    }
    stack<ItemType> traversal1;					   // Create two stacks
    stack<ItemType> traversal2;
	
    int root = 1;
	
    traversal1.push(root);					// Push the root of the tree into the stack.
    while (!traversal1.empty()) {
        root = traversal1.top();
	traversal2.push(root);				// Push the node into the second stack.
	traversal1.pop();
	if (root * 2 <= itemCount) {				
            traversal1.push(root * 2);				// Push the left child of this node into the stack.
	}
	if (root * 2 + 1 <= itemCount) {
	    traversal1.push(root * 2 + 1);					// Push the right child of this node into the stack.
	}
    }
    while (!traversal2.empty()) {				// Push the elements from the second stack into the vector.
        root = traversal2.top();
	result.push_back(items[root]);
	traversal2.pop();
    }
	
    return result; 
}
