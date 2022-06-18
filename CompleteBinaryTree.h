/**
 * @file CompleteBinaryTree.h
 * @author Harry Kim
 * CSC 237, Fall 2018, Assignment 6
 */


#ifndef COMPLETE_BINARY_TREE
#define COMPLETE_BINARY_TREE

#include <vector>

using namespace std;

/**
 * A binary tree that maintains the complete property
 */
template<class ItemType>
class CompleteBinaryTree {
private: 
    static const int DEFAULT_CAPACITY = 6;
    int capacity;
    int itemCount; 
    ItemType* items; // array of items

public:
    /* Constructors, destructor, and assignment operator */
    CompleteBinaryTree();
    ~CompleteBinaryTree();
    CompleteBinaryTree(const CompleteBinaryTree & other);
    CompleteBinaryTree &operator=(const CompleteBinaryTree & other);

    /** 
     * Tests whether this binary tree is empty
     * @return true if the binary tree is empty otherwise false.
     */
    bool isEmpty();

    /**
     * Gets the height of the binary tree
     * @return the height of the binary tree.
     */
    int getHeight();

    /**
     * Gets the number of nodes in the binary tree
     * @return the number of nodes in the binary tree.
     */
    int getNumberOfNodes();

    /**
     * Gets the capacity of the backing array (the amount of total space).
     * @return the capacity of the backing array.
     */
    int getCapacity();

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
    bool add(const ItemType& newData);

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
    bool remove(const ItemType& data);

    /**
     * Removes all the nodes from this binary tree. If the capacity of the
     * backing array is greater than the default capacity, then the capacity of
     * the backing array is changed to the default capacity.
     */
    void clear();
    
    /**
     * Tests whether a given entry occurs in this binary tree.
     * @param anEntry the entry to find.
     * @return true if the entry occurs in the tree, otherwise false.
     */
    bool contains(const ItemType& anEntry);
    
    /**
     * Traverse the tree in preorder and return a vector with the elements in
     * the order of the traversal.
     * @return a vector of the elements in a preorder traversal.
     */
    vector<ItemType> preorderTraverse();

    /**
     * Traverse the tree in inorder and return a vector with the elements in
     * the order of the traversal.
     * @return a vector of the elements in a inorder traversal.
     */
    vector<ItemType> inorderTraverse();

    /**
     * Traverse the tree in postorder and return a vector with the elements in
     * the order of the traversal.
     * @return a vector of the elements in a postorder traversal.
     */
    vector<ItemType> postorderTraverse();
};

#include "CompleteBinaryTree.cpp"
#endif
