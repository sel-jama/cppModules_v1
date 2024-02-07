/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:01:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/06 05:24:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <math.h>
#include <sstream>

class ScalarConverter{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    
        static void convert(const std::string &literal);
        static const std::string detectType(const std::string &literal);
};

void printInt(const std::string &str);
void printChar(const std::string &str);
void printFloat(const std::string &str);
void printDouble(const std::string &str);
bool isZero(const char *s);

#endif