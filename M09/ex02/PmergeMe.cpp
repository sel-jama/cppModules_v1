#include <iostream>
#include <vector>
#include <ctime>
#include "PmergeMe.hpp"

void PmergeMe::printContainer(std::vector<int>& vec) const{
    std::vector<int>::iterator it = vec.begin();
    for(; it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const std::vector<int>& vec) : v(vec) {}

void PmergeMe::sortAndMeasureTime() {
    std::vector<int> container1 = v;

    clock_t start1 = clock();
    fordJohnsonMergeSort(container1, 0, container1.size() - 1);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000000;


    std::cout << "Before: ";
    printContainer(v);

    std::cout << "After: ";
    printContainer(container1);

    std::cout << "Time to process a range of " << v.size() << " elements with container 1: " << time1 << " us" << std::endl;
}

void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void fordJohnsonMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left <= 4) {
            insertionSort(arr, left, right);
        } else {
            int middle = left + (right - left) / 2;
            fordJohnsonMergeSort(arr, left, middle);
            fordJohnsonMergeSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }
}
