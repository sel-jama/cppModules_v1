/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:03:48 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/09 07:52:38 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <utility>

PmergeMe::PmergeMe(const std::vector<int> &vec) : vec(vec){   
}

void PmergeMe::printContainer(std::vector<int>& vec) const{
    std::vector<int>::iterator it = vec.begin();
    for(; it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sortAndmesure(void){
    std::vector<int> container1 = vec;

    clock_t start = clock();
    mergeInserSort(container1);
    clock_t end = clock();
    double time1 = (double)(end - start) / CLOCKS_PER_SEC * 1000000;


    std::cout << "Before: ";
    printContainer(vec);

    std::cout << "After: ";
    printContainer(container1);

    std::cout << "Time to process a range of " << vec.size() << " elements with container 1: " << time1 << " us" << std::endl;

}

bool isOddLength(std::vector<int>& arr) {
    return arr.size() % 2 != 0;
}

int removeStraggler(std::vector<int>& arr) {
    
    int straggler = arr.back();
    arr.pop_back();
    return straggler;
}

void insertion_sort_pairs(std::vector<std::pair<int, int> >& A, int n) {
    if (n <= 0) return;
    
    insertion_sort_pairs(A, n - 1);
    std::pair<int, int> element = A[n];
    int j = n - 1;
    while (j >= 0 && element.second < A[j].second) {
        // A[j + 1] = A[j];
        std::swap(A[j+1], A[j]);
        j--;
    }
    // A[j + 1] = element;
}

std::vector<std::pair<int, int> > createPairs(std::vector<int>& arr) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            pairs.push_back(std::make_pair(std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])));
        } 
        // else {
        //     pairs.push_back(std::make_pair(arr[i], arr[i])); // Replicate the last element for odd-sized input
        // }
    }
    return pairs;
}


std::vector<int> create_s(std::vector<std::pair<int, int> > &pairs, int straggler) {
    std::vector<int> S, pend;

    S.push_back(pairs[0].first);
    S.push_back(pairs[0].second);
    for (size_t i = 1; i < pairs.size(); i++) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }

    // S.insert(S.begin(), pend[0]);
    // pend.erase(pend.begin());
    if (straggler != -1)
        pend.insert(pend.end(), straggler);

    
    for (size_t j = 0; j < pend.size(); j++){
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[j]);
        S.insert(it, pend[j]);
    }

    // if (straggler != -1){
    //     std::vector<int>::iterator it1 = std::lower_bound(S.begin(), S.end(), straggler);
    //     S.insert(it1, straggler);
    // }
    return S;
}

void PmergeMe::mergeInserSort(std::vector<int> &v){
    if (v.size() <= 1)
        return ;

    int straggler = -1;
    if (isOddLength(v))
        straggler = removeStraggler(v);
    std::vector<std::pair<int, int> > pairs = createPairs(v);
    insertion_sort_pairs(pairs, pairs.size() - 1);
    v = create_s(pairs, straggler);
}
