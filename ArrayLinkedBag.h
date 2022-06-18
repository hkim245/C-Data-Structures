/** 
 * @file ArrayLinkedBag.h 
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 3
 */

#ifndef ARRAY_LINKED_BAG_
#define ARRAY_LINKED_BAG_

#include "BagInterface.h"
using namespace std;

template<class ItemType>
class ArrayLinkedBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6;    // Size of the bag.

    struct Cell {
        ItemType item;        // item to store in the bag.
        int next;      // the index to the next item in the bag.
    };

    Cell cells[DEFAULT_CAPACITY];       // Creating an array of cell structs.
    int itemCount;                     // Counter for the number of items found in the bag.
    int maxItems;                 // Max capacity of the bag.
    int head;        // head of the linked chain.
    int free;        // the first free cell available in the linked chain.
	
    /**
    * Gets the index of the target item in the bag.
    * @param target the target item
    * @return result the index of the target item or -1 if the 
    * target item was not found in the bag.
    */
    int getIndexOf(const ItemType& target) const;          
	
    

public: 
    /**
    * Default constructor to initialize the data members.
    */
    ArrayLinkedBag();  
	
    /**
    * Gets the number of items stored in the bag.
    * @return itemCount the number of items stored in the bag.
    */
    int getCurrentSize() const;
	
    /**
    * Checks if the bag is empty.
    * @return itemCount true if the bag is empty or false if the bag is not empty.
    */
    bool isEmpty() const;
	
    /**
    * Adds an item to the bag.
    * @param newEntry the item to be added.
    * @return hasRoomToAdd true if the item was added to the bag
    * or false if the item was not added
    */
    bool add(const ItemType& newEntry);
	
    /**
    * Removes an item from the bag.
    * @param anEntry the item to remove
    * @return canRemoveItem true if the bag item was removed from the bag
    * or false if the bag item was not removed.
    */
    bool remove(const ItemType& anEntry);
	
    /**
    * Clears the items in the bag
    */
    void clear();
	
    /**
    * Checks to see if the item exists in the bag.
    * @param anEntry the item to be checked in the bag.
    * @return found true if the item was found in the bag or false
    * if the item was not found.
    */
    bool contains(const ItemType& anEntry) const;
	
    /** 
    * Gets the frequency of an item in the bag.
    * @param anEntry the item to be counted
    * @return frequency the number of occurrences of the item in the bag.
    */
    int getFrequencyOf(const ItemType& anEntry) const;
	
    /**
    * Stores the items of the bag into a vector.
    * @return bagContents the vector
    */
    vector<ItemType> toVector() const;
};

#include "ArrayLinkedBag.cpp"
#endif
