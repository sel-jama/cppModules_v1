/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:34:28 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/04 23:34:52 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Function to parse the input file
// void    BitcoinExchange::parseInput(void) {
//     std::ifstream file(this->inuptFile);

//     if (!file.is_open()){
//         cerr << "Error: could not open file." << endl;
//         exit(EXIT_FAILURE);
//     }

//     std::string line;
//     while (getline(file, line)){
//         std::stringstream ss(line);
//         std::string dateStr, valueStr;
//         getline(ss, dateStr, '|');
//         getline(ss, valueStr);
//         try {
//             float value = stof(valueStr);
//             inputData[dateStr] = value;
//         } catch (const invalid_argument& e) {
//             cerr << "Error: not a valid number." << endl;
//         }
//     }
// }


void BitcoinExchange::setInputfile(const std::string &filename){
    this->inuptFile = filename;
}

void BitcoinExchange::setDatabase(const std::map<std::string, float> &data){
    this->dataBase = data;
}

// Function to find the closest date in the database
const std::string &BitcoinExchange::findDate(const std::string& date)
{
    std::map<std::string, float>::iterator it = dataBase.upper_bound(date);

    if (it != dataBase.begin())
        return prev(it)->first;
    return NULL;

}

// // Function to calculate bitcoin value
void BitcoinExchange::calculateBitcoin(void){
    // parseInputFile(filename);

    std::ifstream file(this->inuptFile);

    if (!file.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)){
        std::stringstream ss(line);
        std::string dateStr, valueStr;
        getline(ss, dateStr, '|');
        getline(ss, valueStr);
        float value;
        try {
            value = stof(valueStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue ;
        }
        if (value < 0 || value > std::numeric_limits<int>::max()){
            std::cerr << "Error: ";
            if (value < 0)
                std::cerr << "not a positive number.";
            else
                std::cerr << "too large number.";
            std::cerr << std::endl;
        }

        std::string closestDate = findDate(dateStr);
        if (closestDate.empty()){
            std::cerr << "Error: date not found" << std::endl;
            continue ;
        }
        float exchangeRate = dataBase.at(closestDate);
        std::cout << dateStr << " => " << value << " = " << (value * exchangeRate) << std::endl;
    }
}

