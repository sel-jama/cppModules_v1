/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:34:34 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/10 08:56:05 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return EXIT_FAILURE;
    }
    BitcoinExchange obj;
    
    obj.loadData();

    obj.setInputfile(av[1]);
    obj.calculateBitcoin();

    return 0;
}