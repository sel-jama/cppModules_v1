/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:57:18 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 13:57:41 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printFloat(const std::string &str) {
	int flag = 0;
	std::cout << "It's a float" << std::endl;
	const char *s = str.c_str();
	if (isZero(s))
		flag = 1;
	float value = std::strtof(s, nullptr);

	if (str == "-inff" || str == "inff" || str == "+inff" || str == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else{
		std::cout << "char: ";
		if (std::isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		int intValue = static_cast<int>(value);
		std::cout << "int: ";
		if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << intValue << std::endl;
	}
	
	if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else{
		std::cout << "float: " << value;
		if (flag)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;
	}
	
	double DblVal = static_cast<double>(value);
	std::cout << "double: ";
	if (DblVal < std::numeric_limits<double>::min() || DblVal > std::numeric_limits<double>::max())
		std::cout << "impossible";
	else{
		std::cout << DblVal;
		if (flag)
			std::cout << ".0";
	}
	std::cout << std::endl;
}