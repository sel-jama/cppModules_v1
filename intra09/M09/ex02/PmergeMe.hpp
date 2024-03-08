#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe {
public:
    PmergeMe(const std::vector<int>& seq);

    void sortAndMeasureTime();

private:
    std::vector<int> sequence;

    void mergeInsertionSort(std::vector<int>& arr);
    void merge(std::vector<int>& arr, int l, int m, int r);
};

#endif

