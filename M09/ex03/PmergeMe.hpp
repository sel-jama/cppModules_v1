/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:03:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/10 05:54:12 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::list<int> lst;
    
    public:
        PmergeMe(const std::vector<int> &vec, const std::list<int> &lst);
    
        void sortAndmesure(void);
        void mergeInserSort(std::vector<int> &v);
        void mergeInserSort(std::list<int> &l);
};

template <typename T>
void printContainer(T &container);

#endif