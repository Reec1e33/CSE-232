#include <iostream>
#include <vector>
#include "sort.h"

void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int> vec) {

    printVector(vec);
    size_t n = vec.size();
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (vec.at(i - 1) > vec.at(i)) {
                std::swap(vec.at(i - 1), vec.at(i));
                swapped = true;
                printVector(vec);
            }
        }
        --n; // Reduce the range for the next iteration
    } while (swapped);
}




void insertion_sort(std::vector<int> vec) {
    size_t i = 1;
    printVector(vec);
    while (i < vec.size()) {
        size_t j = i;
        while (j > 0 && vec.at(j - 1) > vec.at(j)) {
            std::swap(vec.at(j - 1), vec.at(j));
            printVector(vec); // Print only when a swap occurs
            --j;
        }
        ++i;
    }
}





int partition(std::vector<int>& vec, int lo, int hi) {
    int pivot = vec.at(hi); // Choose the last element as the pivot
    int i = lo;

    for (int j = lo; j < hi; ++j) {
        if (vec.at(j) <= pivot) {
            if (i != j) { // Swap only if indices differ to prevent redundant prints
                std::swap(vec.at(i), vec.at(j));
                printVector(vec);
            }
            ++i;
        }
    }

    if (i != hi) { // Swap pivot only if it's out of position
        std::swap(vec.at(i), vec.at(hi));
        printVector(vec);
    }
    return i; // Return the pivot index
}


void quicksort_recursive(std::vector<int>& vec, int lo, int hi) {
    if (lo >= hi || lo < 0) {
        return; // Ensure valid indices
    }

    int p = partition(vec, lo, hi); // Partition the vector
    quicksort_recursive(vec, lo, p - 1); // Sort the left partition
    quicksort_recursive(vec, p + 1, hi); // Sort the right partition
}


void quicksort_sort(std::vector<int> vec) {
    if (vec.size() <= 1) { // Handle edge case for single-element or empty vector
        printVector(vec);
        return;
    }

    printVector(vec); // Print the initial vector state
    quicksort_recursive(vec, 0, vec.size() - 1);
}

