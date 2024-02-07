/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:33:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/07 07:07:18 by sel-jama         ###   ########.fr       */
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

	// if (str.length() == 1 && str[0] == '0')
	// 	return true;

	const char *s = str.c_str();
	// if (strchr(s, '.'))
	// 	return false;
	// int n = std::atoi(s);
    char* n;
    std::strtol(s, &n, 10);
	if (*n == '\0')
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

void ScalarConverter::convert(const std::string &literal) {
	if (literal.empty())
		return;

	const std::string type = detectType(literal);
	if (type.empty())
		return;

	if (type == "int")
		printInt(literal);
	else if (type == "char")
		printChar(literal);
	else if (type == "float")
		printFloat(literal);
	else if (type == "double")
		printDouble(literal);
}

void printInt(const std::string &str) {
	std::cout << "It's an int" << std::endl;
	const char *s = str.c_str();
	int value = static_cast<int>(std::strtof(s, nullptr));

	std::cout << "char: ";
	if (std::isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void printChar(const std::string &str) {
	std::cout << "It's a char" << std::endl;
	char c;
	for (unsigned long i = 0; i < str.length(); i++) {
		if (isprint(str[i]))
			c = str[i];
	}
	std::cout << "char: ";
	std::cout << "'" << c << "'" << std::endl;

	int value = static_cast<int>(c);
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printFloat(const std::string &str) {
	int flag = 0;
	std::cout << "It's a float" << std::endl;
	const char *s = str.c_str();
	if (isZero(s))
		flag = 1;
	float value = std::strtof(s, nullptr);

	std::cout << "char: ";
	if (std::isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	int intValue = static_cast<int>(value);
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << value;
	if (flag)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << static_cast<double>(value);
	if (flag)
		std::cout << ".0";
	std::cout << std::endl;
}

void printDouble(const std::string &str) {
	int flag = 0;
	std::cout << "It's a double" << std::endl;
	const char *s = str.c_str();
	if (isZero(s))
		flag = 1;
	std::cout << "flag " << flag << std::endl;
	double value = std::strtod(s, nullptr);

	std::cout << "char: ";
	if (std::isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	int intValue = static_cast<int>(value);
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << static_cast<float>(value);
	if (flag)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << value;
	if (flag)
		std::cout << ".0";
	std::cout << std::endl;
}

//     void printFloat(const std::string &str) {
//     const char *s = str.c_str();
//     float value = std::strtof(s, nullptr);

//     std::cout << "char: ";
//     if (isnan(value) || isinf(value))
//         std::cout << "impossible" << std::endl;
//     else if (std::isprint(value))
//         std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
//     else
//         std::cout << "Non displayable" << std::endl;

//     int intValue = static_cast<int>(value);
//     std::cout << "int: " << intValue << std::endl;
//     std::cout << "float: " << value << "f" << std::endl;
//     std::cout << "double: " << static_cast<double>(value) << std::endl;
// }

// void printDouble(const std::string &str) {
//     const char *s = str.c_str();
//     double value = std::strtod(s, nullptr);

//     std::cout << "char: ";
//     if (isnan(value) || isinf(value))
//         std::cout << "impossible" << std::endl;
//     else if (std::isprint(value))
//         std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
//     else
//         std::cout << "Non displayable" << std::endl;

//     int intValue = static_cast<int>(value);
//     std::cout << "int: " << intValue << std::endl;
//     std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
//     std::cout << "double: " << value << std::endl;
// }


bool isZero(const char *s){
	const char *point = strchr(s, '.');
	if (!point)
		return false;
	point++;
	while ((*point) != '\0'){
		if (*point == 'f' && *(point + 1) == '\0')
			return true;
		if (*point != '0')
			return false;
		point++;
	}
	return true;
}
