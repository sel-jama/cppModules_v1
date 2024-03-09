/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:39:19 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/09 03:39:20 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid input sequence." << std::endl;
            return 1;
        }
        sequence.push_back(num);
    }

    PmergeMe sorter(sequence);
    sorter.sortAndMeasureTime();

    return 0;
}
