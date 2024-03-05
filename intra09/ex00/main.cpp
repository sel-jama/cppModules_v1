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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return EXIT_FAILURE;
    }
    const string& filename = argv[1];
    
    map<string, float> database = {
        {"2011-01-01", 0.3},
        {"2011-01-05", 0.2},
        {"2011-01-10", 0.1},
        {"2012-01-15", 0.7}
    };

    BitcoinExchange(database, filename);

    return 0;
}