/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:34:34 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/04 23:38:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return EXIT_FAILURE;
    }
    BitcoinExchange obj;
    
    std::map<std::string, float> database = {
        {"2011-01-01", 0.3},
        {"2011-01-05", 0.2},
        {"2011-01-10", 0.1},
        {"2012-01-15", 0.7}
    };

    obj.setInputfile(av[1]);
    obj.setDatabase(database);
    obj.calculateBitcoin();

    return 0;
}