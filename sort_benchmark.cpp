/**
 * @file sort_benchmark.cpp
 * @author Harry Kim
 * @brief compare basic sorting algorithms
 * CSC237, Fall 2018, Assignment 5
 */
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <cstddef>

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"

using namespace std;

void bubbleSort(int, int*, int);			// Function prototypes.
void selectionSort(int, int*, int);
void insertionSort(int, int*, int);
void mergeSort(int, int, int*, int);
void quickSort(int, int, int*, int);
int* makeRandomArray(int, int);

/**
 * Call the functions.
 * @return 0 exit the program.
 */
int main() {
    const int seed = 370;                   // Initialize the seed for the random number generator.

    int* sortArray = NULL;                            // Initialize variables for functions.
    int counter = 0, comparisons = 0;
    
    selectionSort(comparisons, sortArray, seed);
    bubbleSort(comparisons, sortArray, seed);
    insertionSort(comparisons, sortArray, seed);
    mergeSort(comparisons, counter, sortArray, seed);
    quickSort(comparisons, counter, sortArray, seed);
	
    return 0;
}

/**
 * Use the bubble sort to sort an array and count 
 * the number of comparisons made between elements.
 * @param comparisons a counter for the number of comparisons made.
 * @param sortArray a pointer.
 * @param seed the seed for the random number generator.
 */	
void bubbleSort(int comparisons, int* sortArray, int seed) {
    cout << left;
    cout << setw(26) << "Bubble sort";
    sortArray = makeRandomArray(10, seed);
    comparisons = bubblesort(sortArray, 10);
    cout << setw(11) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(100, seed);
    comparisons = bubblesort(sortArray, 100);
    cout << setw(12) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(1000, seed);
    comparisons = bubblesort(sortArray, 1000);
    cout << setw(14) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(10000, seed);
    comparisons = bubblesort(sortArray, 10000);
    cout << comparisons << endl;
    delete[] sortArray;
}

/**
 * Use the selection sort to sort an array of different sizes and count 
 * the number of comparisons made between elements.
 * @param comparisons a counter for the number of comparisons made.
 * @param sortArray a pointer.
 * @param seed the seed for the random number generator.
 */	
void selectionSort(int comparisons, int* sortArray, int seed) {
    cout << left;
	cout << setw(38) << "                          10" << setw(13) << "100" << setw(15) << "1000" << "10000" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << setw(26) << "Selection sort";
    sortArray = makeRandomArray(10, seed);
    comparisons = selectionsort(sortArray, 10);
    cout << setw(11) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(100, seed);
    comparisons = selectionsort(sortArray, 100);
    cout << setw(12) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(1000, seed);
    comparisons = selectionsort(sortArray, 1000);
    cout << setw(14) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(10000, seed);
    comparisons = selectionsort(sortArray, 10000);
    cout << comparisons << endl;
    delete[] sortArray;
}

/**
 * Use the insertion sort to sort an array of different sizes and count 
 * the number of comparisons made between elements.
 * @param comparisons a counter for the number of comparisons made.
 * @param sortArray a pointer.
 * @param seed the seed for the random number generator.
 */	
void insertionSort(int comparisons, int* sortArray, int seed) {
    cout << left;
    cout << setw(26) << "Insertion sort";
    sortArray = makeRandomArray(10, seed);
    comparisons = insertionsort(sortArray, 10);
    cout << setw(11) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(100, seed);
    comparisons = insertionsort(sortArray, 100);
    cout << setw(12) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(1000, seed);
    comparisons = insertionsort(sortArray, 1000);
    cout << setw(14) << comparisons;
    delete[] sortArray;
    sortArray = makeRandomArray(10000, seed);
    comparisons = insertionsort(sortArray, 10000);
    cout << comparisons << endl;
    delete[] sortArray;
}

/**
 * Use the merge sort to sort an array of different sizes and count 
 * the number of comparisons made between elements.
 * @param comparisons a counter for the number of comparisons made.
 * @param counter a counter for the number of comparisons made in the mergesort function.
 * @param sortArray a pointer.
 * @param seed the seed for the random number generator.
 */	
void mergeSort(int comparisons, int counter, int* sortArray, int seed) {
    cout << left;
    cout << setw(26) << "Merge sort";
    sortArray = makeRandomArray(10, seed);
    comparisons = mergesort(sortArray, 0, 9, counter);
    cout << setw(11) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(100, seed);
    comparisons = mergesort(sortArray, 0, 99, counter);
    cout << setw(12) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(1000, seed);
    comparisons = mergesort(sortArray, 0, 999, counter);
    cout << setw(14) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(10000, seed);
    comparisons = mergesort(sortArray, 0, 9999, counter);
    cout << comparisons << endl;
    counter = 0;
    delete[] sortArray;
}

/**
 * Use the quick sort to sort an array of different sizes and count 
 * the number of comparisons made between elements.
 * @param comparisons a counter for the number of comparisons made.
 * @param counter a counter for the number of comparisons made in the quicksort function.
 * @param sortArray a pointer.
 * @param seed the seed for the random number generator.
 */	
void quickSort(int comparisons, int counter, int* sortArray, int seed) {
    cout << left;
    cout << setw(26) << "Quick sort";
    sortArray = makeRandomArray(10, seed);
    comparisons = quicksort(sortArray, 0, 9, counter);
    cout << setw(11) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(100, seed);
    comparisons = quicksort(sortArray, 0, 99, counter);
    cout << setw(12) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(1000, seed);
    comparisons = quicksort(sortArray, 0, 999, counter);
    cout << setw(14) << comparisons;
    counter = 0;
    delete[] sortArray;
    sortArray = makeRandomArray(10000, seed);
    comparisons = quicksort(sortArray, 0, 9999, counter);
    cout << comparisons << endl;
    delete[] sortArray;
}

/**
 * Generate an array of random integers
 * @param n the size of the array
 * @param seed the seed for the random number generator
 * @return a pointer to a new array
 * @note the client is responsible for deleting the array with delete[]
 */
int* makeRandomArray(int size, int seed) {
    srand(seed);
    int* sortArray = new int[size];
    for (int i = 0; i < size; i++) {
       sortArray[i] = rand() % 1000;
    }
    return sortArray;
}
