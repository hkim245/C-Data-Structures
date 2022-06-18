/**
 * @file quicksort.hpp
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 5
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

static const int MIN_SIZE  = 10; // Smallest size of an array that quicksort will sort

/**
 * Sorts the items in an array into ascending order.
 * @pre  None.
 * @post  theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @return the number of comparisons
 */
template<class ItemType>
int insertionSort(ItemType theArray[], int first, int last, int& counter) {
    for (int unsorted = first + 1; unsorted <= last; unsorted++) {
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > first) && (theArray[loc - 1] > nextItem)) {
            theArray[loc] = theArray[loc - 1];
            loc--;
            counter++;
        }
        if ((loc > first) && (theArray[loc - 1] <= nextItem)) {
            counter++;
        }
        theArray[loc] = nextItem;
    }
    return counter;
}

/**
 * Arranges two specified array entries into sorted order by
 * exchanging them, if necessary.
 * @param theArray  The given array.
 * @param i  The index of the first entry to consider in theArray.
 * @param j  The index of the second entry to consider in theArray.
 * */
template<class ItemType>
void order(ItemType theArray[], int i, int j, int& counter) {
    counter++;
    if (theArray[i] > theArray[j]) {
        std::swap(theArray[i], theArray[j]);
    }
}

/** 
 * Arranges the first, middle, and last entry in an array in sorted order.
 * @pre  theArray[first..last] is an array; first <= last.
 * @post  theArray[first..last] is is arranged so that its
 * first, middle, and last entries are in sorted order.
 * @param theArray  The given array.
 * @param first  The first entry to consider in theArray.
 * @param last  The last entry to consider in theArray.
 * @return  The index of the middle entry.
 */
template<class ItemType>
int sortFirstMiddleLast(ItemType theArray[], int first, int last, int& counter) {
    int mid = first + (last - first) / 2;
    order(theArray, first, mid, counter); // Make theArray[first] <= theArray[mid]
    order(theArray, mid, last, counter);  // Make theArray[mid] <= theArray[last]
    order(theArray, first, mid, counter); // Make theArray[first] <= theArray[mid]

    return mid;
}

/**
 * Partitions the entries in an array about a pivot entry for quicksort.
 * @pre  theArray[first..last] is an array; first <= last.
 * @post  theArray[first..last] is partitioned such that:
 * S1 = theArray[first..pivotIndex-1] <= pivot * theArray[pivotIndex] == pivot
 * S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first entry to consider in theArray.
 * @param last  The last entry to consider in theArray.
 * @return  The index of the pivot.
 */
template<class ItemType>
int partition(ItemType theArray[], int first, int last, int& counter) {
    // Choose pivot using median-of-three selection
    int pivotIndex = sortFirstMiddleLast(theArray, first, last, counter);
    // Reposition pivot so it is last in the array
    std::swap(theArray[pivotIndex], theArray[last - 1]);
    pivotIndex = last - 1;
    ItemType pivot = theArray[pivotIndex];
    // Determine the regions S1 and S2
    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;
    
    bool done = false;
    while (!done) {
        // Locate first entry on left that is >= pivot
        while (theArray[indexFromLeft] < pivot) {
            indexFromLeft = indexFromLeft + 1;
            counter++;
        }
        counter++;
        // Locate first entry on right that is <= pivot
        while (theArray[indexFromRight] > pivot) {
            indexFromRight = indexFromRight - 1;
            counter++;
        }
        counter++;
        if (indexFromLeft < indexFromRight) {
            std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
            indexFromLeft = indexFromLeft + 1;
            indexFromRight = indexFromRight - 1;
        }
        else {
            done = true;
        }
    }
 
    // Place pivot in proper position between S1 and S2, and mark its new location
    std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
    pivotIndex = indexFromLeft;
    return pivotIndex;
}

/**
 * Sorts an array into ascending order. Uses the quick sort with
 * median-of-three pivot selection for arrays of at least MIN_SIZE
 * entries, and uses the insertion sort for other arrays.
 * @pre  theArray[first..last] is an array.
 * @post  theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @return the number of comparisons
 */
template<class ItemType>
int quicksort(ItemType theArray[], int first, int last, int& counter) {
    if (last - first + 1 < MIN_SIZE) {
        counter = insertionSort(theArray, first, last, counter);
    }
    else {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last, counter);
        // Sort subarrays S1 and S2        
        quicksort(theArray, first, pivotIndex - 1, counter);
        quicksort(theArray, pivotIndex + 1, last, counter);
    }
    return counter;
}

#endif
