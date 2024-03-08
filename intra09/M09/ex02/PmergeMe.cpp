#include <iostream>
#include <vector>
#include <ctime>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& seq) : sequence(seq) {}

void PmergeMe::sortAndMeasureTime() {
    std::vector<int> container1 = sequence;
    std::vector<int> container2 = sequence;

    clock_t start1 = clock();
    mergeInsertionSort(container1);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000000;

    clock_t start2 = clock();
    mergeInsertionSort(container2);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000000;

    // Display results
    std::cout << "Before:";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << " " << sequence[i];
    }
    std::cout << std::endl;

    std::cout << "After:";
    for (size_t i = 0; i < container1.size(); ++i) {
        std::cout << " " << container1[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sequence.size() << " elements with container 1: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << sequence.size() << " elements with container 2: " << time2 << " us" << std::endl;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

