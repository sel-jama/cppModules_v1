#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe {
    private:
        std::vector<int> v;
    
    public:
        PmergeMe(const std::vector<int>& seq);

        void sortAndMeasureTime();
        void printContainer(std::vector<int>& vec) const;
};
void fordJohnsonMergeSort(std::vector<int>& arr, int left, int right);

#endif

