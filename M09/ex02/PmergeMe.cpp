/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:03:48 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/10 10:11:09 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <utility>

PmergeMe::PmergeMe(const std::vector<int> &vec, const std::list<int> &lst) : vec(vec), lst(lst){   
}

PmergeMe::PmergeMe(const PmergeMe& other){
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other){
    this->vec = other.vec;
    this->lst = other.lst;
    return *this;
}

PmergeMe::~PmergeMe(){}

//starter function to sort and mesure two diffrent containers
void PmergeMe::sortAndmesure(void){
    std::vector<int> container1 = vec;
    std::list<int> container2 = lst;

    clock_t start1 = clock();
    mergeInserSort(container1);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Before: ";
    printContainer(vec);

    std::cout << "After : ";
    printContainer(container1);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time1 << " us" << std::endl;
    
    std::cout << std::endl;
    clock_t start2 = clock();
    mergeInserSort(container2);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Before: ";
    printContainer(lst);

    std::cout << "After : ";
    printContainer(container2);

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << time2 << " us" << std::endl;
}

//helper template functions
template <typename T>
void printContainer(T &container){
    typename T::iterator it = container.begin();
    for(; it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
bool isOddLength(T& arr) {
    return arr.size() % 2 != 0;
}

template <typename T>
int removeStraggler(T& arr) {
    
    int straggler = arr.back();
    arr.pop_back();
    return straggler;
}


//merge_insert sort for std::vector
void insertion_sort_pairs(std::vector<std::pair<int, int> >& A, int n) {
    if (n <= 0) return;
    
    insertion_sort_pairs(A, n - 1);
    std::pair<int, int> element = A[n];
    int j = n - 1;
    while (j >= 0 && element.second < A[j].second) {
        std::swap(A[j+1], A[j]);
        j--;
    }
}

std::vector<std::pair<int, int> > createPairs(std::vector<int>& arr) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size())
            pairs.push_back(std::make_pair(std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])));
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

    if (straggler != -1)
        pend.insert(pend.end(), straggler);

    for (size_t j = 0; j < pend.size(); j++){
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[j]);
        S.insert(it, pend[j]);
    }

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



//merge-insert sort for std::list
std::list<std::pair<int, int> > createPairs(std::list<int>& lst) {
    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end();) {
        int a = *it;
        it++;
        int b = *it;
        it++;
        pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
    }
    return pairs;
}

void insertion_sort_pairs(std::list<std::pair<int, int> >& A, int n) {
    if (n <= 0) return;
    
    insertion_sort_pairs(A, n - 1);
    
    std::list<std::pair<int, int> >::iterator it = A.begin();
    std::advance(it, n);
    std::pair<int, int> element = *it;
    
    std::list<std::pair<int, int> >::iterator j = it;
    --j;
    
    while (j != A.begin() && element.second < j->second) {
        std::swap(*std::next(j), *j);
        --j;
    }
    if (element.second < j->second)
         std::swap(*std::next(j), *j);
}

std::list<int> create_s(std::list<std::pair<int, int> >& pairs, int straggler) {
    std::list<int> S, pend;
    std::list<std::pair<int, int> >::iterator it = pairs.begin();

    S.push_back(pairs.front().first);
    S.push_back(pairs.front().second);
    it++;

    while (it != pairs.end()) {
        S.push_back((*it).second);
        pend.push_back((*it).first);
        ++it;
    }

    if (straggler != -1)
        pend.push_back(straggler);

    std::list<int>::iterator i = pend.begin();
    while (i != pend.end()) {
        std::list<int>::iterator ins_it = std::lower_bound(S.begin(), S.end(), *i);
        S.insert(ins_it, *i);
        ++i;
    }
    return S;
}

void PmergeMe::mergeInserSort(std::list<int>& l){
    if (l.size() <= 1)
        return;

    int straggler = -1;
    if (isOddLength(l))
        straggler = removeStraggler(l);
    
    std::list<std::pair<int, int> > pairs = createPairs(l);
    insertion_sort_pairs(pairs, pairs.size() - 1);
    l = create_s(pairs, straggler);
}
