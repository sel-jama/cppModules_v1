/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:58:05 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 13:58:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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