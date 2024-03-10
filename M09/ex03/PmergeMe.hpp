/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:03:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/09 07:50:39 by sel-jama         ###   ########.fr       */
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
#include <algorithm>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::list<int> lst;
    
    public:
        PmergeMe(const std::vector<int> &vec);
    
        void sortAndmesure(void);
        void mergeInserSort(std::vector<int> &v);
        void printContainer(std::vector<int>& vec) const;
};

#endif