/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:34:32 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/07 04:53:01 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class BitcoinExchange{
    private:
        std::map<std::string, float> dataBase;
        std::string inuptFile;
    
    public:
        void setInputfile(const std::string &filename);
        // std::map<std::string, float> &parseInput(void);
        void calculateBitcoin(void);
        const std::string &findDate(const std::string & date);
        void loadData(void);
        void checkLimits(const std::string& str) const;
        void validateDate(const std::string& date) const;
        void validateLine(const std::string& line) const;

        class tooLarge : public std::exception{
            public:
                const char *what() const throw() ;
        };

        class tooLow : public std::exception{
            public:
                const char *what() const throw() ;
        };

        class InvalidDate : public std::exception{
            public:
                const char *what() const throw() ;
        };
};


#endif