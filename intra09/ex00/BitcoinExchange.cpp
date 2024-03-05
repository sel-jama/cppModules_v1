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
map<string, float> parseInputFile(const string& filename) {
    std::map<string, float> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string dateStr, valueStr;
        getline(ss, dateStr, '|');
        getline(ss, valueStr);
        try {
            float value = stof(valueStr);
            data[dateStr] = value;
        } catch (const invalid_argument& e) {
            cerr << "Error: not a valid number." << endl;
        }
    }
    return data;
}

// // Function to find the closest date in the database
// string findDate(const map<string, float>& database, const string& date) {
//     std::map<string, float>::iterator it = database.lower_bound(date);
//     if (it == database.begin())
//         return it->first;
//     else if (it == database.end())
//         return prev(it)->first;
//     else{
//         const string& date1 = it->first;
//         const string& date2 = prev(it)->first;
//         if (date1 <= date && date2 <= date)
//             return date1;
//         else
//             return date2;
//     }
// }

// // Function to calculate bitcoin value
// void calculateBitcoinValue(const std::map<string, float>& database, const std::string& filename) {
//     std::map<string, float> inputData = parseInputFile(filename);
//     for (const std::map<string, float>::iterator& entry : inputData) {
//         const std::string& date = entry.first;
//         float value = entry.second;
//         std::string closestDate = findDate(database, date);
//         float exchangeRate = database.at(closestDate);
//         std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
//     }
// }

