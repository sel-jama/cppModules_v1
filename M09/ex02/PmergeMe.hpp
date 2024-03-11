/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:03:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/10 08:58:16 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>

class PmergeMe{
    private:
        PmergeMe();
        std::vector<int> vec;
        std::list<int> lst;
    
    public:
        PmergeMe(const std::vector<int> &vec, const std::list<int> &lst);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);
        ~PmergeMe();
    
        void sortAndmesure(void);
        void mergeInserSort(std::vector<int> &v);
        void mergeInserSort(std::list<int> &l);
};

template <typename T>
void printContainer(T &container);

#endif