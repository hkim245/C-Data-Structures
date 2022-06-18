/** 
 * @file ArrayLinkedBag.cpp
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 3
 */

#include "ArrayLinkedBag.h"
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

/**
 * Default constructor to initialize the data members.
 */
template <class ItemType>
ArrayLinkedBag<ItemType>::ArrayLinkedBag(): itemCount(0), maxItems(DEFAULT_CAPACITY), head(-1), free(0) {
    for (int i = 0; i < maxItems; i++) {           
        cells[i].item = "";                     // Creating the free list for the linked chain.
        cells[i].next = i + 1;
        if (i == maxItems - 1) {
            cells[i].next = -1;
        }
    }    
} 

/**
 * Gets the number of items stored in the bag.
 * @return itemCount the number of items stored in the bag.
 */
template <class ItemType>
int ArrayLinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

/**
 * Checks if the bag is empty.
 * @return itemCount true if the bag is empty or false if the bag is not empty.
 */
template <class ItemType>
bool ArrayLinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/**
 * Adds an item to the bag.
 * @param newEntry the item to be added.
 * @return hasRoomToAdd true if the item was added to the bag
 * or false if the item was not added
 */
template <class ItemType>
bool ArrayLinkedBag<ItemType>::add(const ItemType& newEntry) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd) {          // If there is room to add an item to the bag.
        if (itemCount == 0) {                // If the bag is empty, run this statement.
            cells[free].item = newEntry;           // Use the first free cell available to store the item.
            cells[free].next = -1;             // Last cell in the linked chain has the next data field as -1.
        }
        else {
            cells[free].item = newEntry;     // If the bag is not empty, run this statement.
            cells[free].next = head;         // The cell that has been added is now the head of the linked chain.
	}
        itemCount++;               // Number of items increases by one.
        head = free;
        for (int i = 0; i < maxItems; i++) {
            if (cells[i].item == "") {
                free = i;                  // Locate the first free cell.
                break;
            }
        }
    }
    if (!hasRoomToAdd) {             // If the bag is full, the free is -1.
        free = -1;
    }
    return hasRoomToAdd;
}

/**
 * Removes an item from the bag.
 * @param anEntry the item to remove
 * @return canRemoveItem true if the bag item was removed from the bag
 * or false if the bag item was not removed.
 */
template <class ItemType>
bool ArrayLinkedBag<ItemType>::remove(const ItemType& anEntry) {
    if (itemCount == 0) {              // If the bag is empty, return false.
        return false;
    }
    int locatedIndex = getIndexOf(anEntry);              // Use getIndexOf function to locate target index.
    bool canRemoveItem = locatedIndex > -1;         // If the item is found, run this statement.
    if (canRemoveItem) {
        if (head == locatedIndex) {             // If the head of the linked chain is the located index, run this statement.
            head = cells[locatedIndex].next;            // The head of the linked chain is the cell after the located index.
        }
        for (int i = 0; i < itemCount; i++) {
            if (cells[i].next == locatedIndex) {                // If the next data field of a cell points to the cell of the located index, run this statement.
                cells[i].next = cells[locatedIndex].next;      // The cell before the cell of the located index has its next data field changed to the cell after the located index.
                break;
            }
        }
        if (itemCount < maxItems) {               // If the bag is not full, run this statement.
            cells[locatedIndex].item = cells[free].item;        // Replace the removed item with the first free cell available in the linked chain.
            cells[locatedIndex].next = free;
        }
        else if (itemCount == maxItems) {              // If the bag is full, run this statement.
            cells[locatedIndex].item = "";                  // Create a free cell.
            cells[locatedIndex].next = -1;
        }
        if (locatedIndex < free || free == -1) {          
            free = locatedIndex;                  // If the removed cell is the first free cell in the linked chain, then free will equal the located index.
        }
        itemCount--;           // Decrease the size of the bag by one.
    }
    return canRemoveItem;
}

/**
 * Clears the items in the bag
 */
template <class ItemType>
void ArrayLinkedBag<ItemType>::clear() {
    itemCount = 0;
}

/**
 * Checks to see if the item exists in the bag.
 * @param anEntry the item to be checked in the bag.
 * @return found true if the item was found in the bag or false
 * if the item was not found.
 */
template <class ItemType>
bool ArrayLinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    if (itemCount == 0) {             // Check if the bag is empty.
        return false;
    }
    bool found = false;
    int curIndex = head;
    while (!found) {                   
        if (anEntry == cells[curIndex].item) {            // If the item is found, run this statement.
            found = true;
        }
        if (cells[curIndex].next == -1) {             // If the item is the last item in the bag, then break out of the loop.
            break;
        }
        curIndex = cells[curIndex].next;          // Go to the next cell in the linked chain.
    }
    return found;
}

/**
 * Stores the items of the bag into a vector.
 * @return bagContents the vector
 */
template <class ItemType>
vector<ItemType> ArrayLinkedBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    int index = head;
    while (itemCount > 0) {
        bagContents.push_back(cells[index].item);
        if (cells[index].next == -1) {             // If the item is the last item in the bag, then break out of the loop.
            break;
        }
        index = cells[index].next;              // Go to the next cell in the linked chain.
    }
    return bagContents;
}

/**
 * Gets the index of the target item in the bag.
 * @param target the target item
 * @return result the index of the target item or -1 if the 
 * target item was not found in the bag.
 */
template <class ItemType>
int ArrayLinkedBag<ItemType>::getIndexOf(const ItemType& target) const {
    if (itemCount == 0) {             // Check if the bag is empty.
        return -1;
    }
    bool isFound = false;
    int result = -1;
    int searchIndex = head;

    while (!isFound && itemCount > 0) {                
        isFound = (cells[searchIndex].item == target);           // If the target matches the item in the bag, then the item is found.
        if (isFound) {
            result = searchIndex;
        }
        if (cells[searchIndex].next == -1) {                // If the item is the last item in the linked chain, then break out of the loop.
            break;
        }
        searchIndex = cells[searchIndex].next;             // Go to the next cell in the linked chain.
    }
    return result;
}

/** 
 * Gets the frequency of an item in the bag.
 * @param anEntry the item to be counted
 * @return frequency the number of occurrences of the item in the bag.
 */
template <class ItemType>
int ArrayLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    if (itemCount == 0) {             // Check if the bag is empty.
        return 0;
    }
    int frequency = 0;
    int curIndex = head;
    while (itemCount > 0) {                  
        if (cells[curIndex].item == anEntry) {              // If the item in the bag is equal to the entry, then increase frequency by one.
            frequency++;
        }
        if (cells[curIndex].next == -1) {             // If the item is the last item in the bag, then break out of the loop.
            break;
        }
        curIndex = cells[curIndex].next;             // Go to the next cell in the linked chain.
       
    }        
    return frequency;
}
