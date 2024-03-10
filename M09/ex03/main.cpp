/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 04:07:47 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/10 05:54:30 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 2) {
        std::cerr << "Error: No sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    long num;
    char *endptr;
    for (int i = 1; i < ac; ++i) {
        num = strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || num < 0 || num > INT_MAX) {
            std::cerr << "Error: Invalid input sequence." << std::endl;
            return 1;
        }
        vec.push_back(num);
        lst.push_back(num);
    }

    PmergeMe sorter(vec, lst);
    sorter.sortAndmesure();

    
    return 0;
}