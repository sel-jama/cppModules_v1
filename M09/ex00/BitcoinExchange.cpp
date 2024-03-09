/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:34:28 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/08 03:43:01 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other){
    this->dataBase = other.dataBase;
    this->inuptFile = other.inuptFile;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

float ft_stof(const std::string &str){
    char *endptr;
    errno = 0;
    float value = strtof(str.c_str(), &endptr);

    if (*endptr != '\0' || errno == ERANGE)
        throw (std::invalid_argument("Invalid argument ."));

    return value;
}

void BitcoinExchange::setInputfile(const std::string &filename){
    this->inuptFile = filename;
}

const std::string &BitcoinExchange::findDate(const std::string& date)
{
    std::map<std::string, float>::iterator it = dataBase.upper_bound(date);

    if (it != dataBase.begin())
        return prev(it)->first;
    return it->first;

}

void BitcoinExchange::checkLimits(const std::string& str) const{
    std::istringstream iss(str);
    double value;
    iss >> value;
    
    if (value > 1000)
        throw tooLarge();
    
    if (value < 0)
        throw tooLow();
}

void BitcoinExchange::validateDate(const std::string& date) const{
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3 ||
        m < 1 || m > 12 || d < 1 || d > 31 ||
        ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) ||
        (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? d > 29 : d > 28)) {
        throw InvalidDate();
    }

}

void BitcoinExchange::validateLine(const std::string& line) const{
    size_t pos = line.find('|');

    if (line.length() < 14 || pos == std::string::npos || line.at(4) != '-' 
        || line.at(7) != '-' || line.at(pos+1) != ' ' || line.at(pos-1) != ' ')
            throw InvalidDate();
}

void BitcoinExchange::calculateBitcoin(void){
    std::ifstream file(this->inuptFile);

    if (!file.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    getline(file, line);
    if (line != "date | value"){
        std::cerr << "Error: bad input !!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    while (getline(file, line)){
        float value;
        std::stringstream ss(line);
        std::string dateStr, valueStr;
        getline(ss, dateStr, '|');
        getline(ss, valueStr);
        
        try{
            validateLine(line);
            validateDate(dateStr);
            checkLimits(valueStr);
            value = ft_stof(valueStr);
        } 
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue ;
        }
        catch (InvalidDate &e){
            std::cerr << "Error: " << e.what() << "=> " << dateStr << std::endl;
            continue ;
        }
        catch (std::exception &e){
            std::cerr << "Error: " << e.what() << std::endl;
            continue ;
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

void BitcoinExchange::loadData(void){
    std::ifstream data("cpp_09/data.csv");

    if (!data.is_open()){
            std::cerr << "Failed to open database file " << std::endl;
            exit(EXIT_FAILURE);
    }
    
    std::string line;
    getline(data, line);
    while (getline(data, line)){
        std::stringstream ss(line);
        std::string date, strValue;
        getline(ss, date, ',');
        getline(ss, strValue);
        float value = ft_stof(strValue);
        this->dataBase[date] = value; 
    }
}

const char *BitcoinExchange::tooLarge::what() const throw() {
    return "too large number.";
}

const char *BitcoinExchange::tooLow::what() const throw() {
    return " not a positive number.";
}

const char *BitcoinExchange::InvalidDate::what() const throw() {
    return " bad input ";
}