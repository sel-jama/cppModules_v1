/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:58:05 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 19:01:58 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printDouble(const std::string &str) {
	int flag = 0;
	std::cout << "It's a double" << std::endl;
	const char *s = str.c_str();
	if (isZero(s))
		flag = 1;
		
	double value = std::strtod(s, nullptr);

	if (str == "-inf" || str == "inf" || str == "+inf" || str == "nan"){
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
	
	std::cout << "float: ";
	float fltValue = static_cast<float>(value);
	if (fltValue < -std::numeric_limits<float>::max() || fltValue > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else{
		std::cout << fltValue;
		if (flag)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;
	}
	
	std::cout << "double: " << value;
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		std::cout << "impossible";
	else{
		if (flag)
			std::cout << ".0";
	}
	std::cout << std::endl;
}