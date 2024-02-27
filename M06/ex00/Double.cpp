/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:58:05 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/27 08:40:59 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printDouble(const std::string &str) {
	int flag = 0;
	const char *s = str.c_str();
	if (isZero(s))
		flag = 1;
		
	double value = std::strtod(s, nullptr);

	if (isPseudo(str)){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else{
		std::cout << "char: ";
		if (ft_isprint(value))
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
	float f = static_cast<float>(value);
	if (!isPseudo(str) && (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max()))
		std::cout << "impossible" << std::endl;
	else{
		std::cout << f;
		if (flag)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;
	}
	
	std::cout << "double: " << value;
	if (!isPseudo(str) && (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max()))
		std::cout << "impossible";
	else{
		if (flag)
			std::cout << ".0";
	}
	std::cout << std::endl;
}