/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:33:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/05 05:19:20 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void)other;
    return (*this);
}

bool isInt(const std::string &str){
    // unsigned long i;
    // for (i = 0; i < str.length(); i++){
    //     if (str[i] != '0')
    //         break;
    // }
    // if (i == str.length())
    //     return true;

    if (str.length() == 1 && str[0] == '0')
        return true;
    
    const char *s = str.c_str();
    if (strchr(s, '.'))
        return false;
    int n = std::atoi(s);
    if (n)
        return true;
    return false;
}

bool isChar(const std::string &str){
    if (str.length() == 1)
        return true;
    return false;
}

bool isFloat(const std::string &str){
    const char *s = str.c_str();
    if (strchr(s, '.') && str[0] != '.' && str[str.length() - 1] == 'f'){
        return true;
    }
    return false;
}

bool isDouble(const std::string &str){
    const char *s = str.c_str();
    if (strchr(s, '.') && str[0] != '.' && str[str.length() - 1] != 'f'){
        return true;
    }
    return false;
}

const std::string ScalarConverter::detectType(const std::string &literal){
    if (isInt(literal))
        return "int";
    else if (isChar(literal))
        return "char";
    else if (isFloat(literal))
        return "float";
    else if (isDouble(literal))
        return "double";
    return "";
}

void printInt(const std::string &str){
    const char *s = str.c_str();
    int i = std::atoi(s);
    
    std::cout << "char: ";
    char c = static_cast<char>(i);
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    
    std::cout << "float: " << i << ".0f" << std::endl;

    std::cout << "double: " << i << ".0" << std::endl;
}

void printChar(const std::string &str){
    char c;
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (isprint(str[i]))
            c = str[i];
    }
    std::cout << "char: ";
    std::cout << "'" << c << "'" << std::endl;
    
    int i = (int)c;
    std::cout << "int: " << i << std::endl;
    
    std::cout << "float: " << i << ".0f" << std::endl;

    std::cout << "double: " << i << ".0" << std::endl;
}

void printFloat(const std::string &str){ 
    const char *s = str.c_str();
    float f = atof(s);
    
    std::cout << "char: ";
    char c = static_cast<char>(f);
    if (c)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    int i = (int)f;
    std::cout << "int: " << i << std::endl;
    
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << f << std::endl;
}

void printDouble(const std::string &str){
    const char *s = str.c_str();
    double d = strtod(s, NULL);
    
    std::cout << "char: ";
    char c = static_cast<char>(d);
    if (c)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    int i = (int)d;
    std::cout << "int: " << i << std::endl;
    
    float f = (float)d;
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal){
    if (!literal[0])
        return ;
    const std::string type = detectType(literal);
    if (type == "")
        return ;
    if (type == "int")
        printInt(literal);
    else if (type == "char")
        printChar(literal);
    else if (type == "float")
        printFloat(literal);
    else if (type == "double")
        printDouble(literal);
}
