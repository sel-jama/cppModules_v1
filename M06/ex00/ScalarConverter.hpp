/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:01:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/27 06:29:05 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <math.h>
#include <limits>

class ScalarConverter{
    ScalarConverter();
    ~ScalarConverter();
    
    public:
        static void convert(const std::string &literal);
        static const std::string detectType(const std::string &literal);
};

void printInt(const std::string &str);
void printChar(const std::string &str);
void printFloat(const std::string &str);
void printDouble(const std::string &str);
bool isZero(const char *s);
bool isDouble(const std::string &str);
bool isFloat(const std::string &str);
bool isInt(const std::string &str);
bool isChar(const std::string &str);
bool isPseudo(const std::string &s);
bool ft_isprint(char c);

#endif