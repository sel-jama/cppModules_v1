/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:06 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/27 06:31:27 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printInt(const std::string &str) {
	const char *s = str.c_str();
	int value = std::strtol(s, nullptr, 10);

	std::cout << "char: ";
	if (ft_isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << ".0f" << std::endl;
	
	std::cout << "double: ";
	double d = static_cast<double>(value);
	if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << ".0" << std::endl;
}