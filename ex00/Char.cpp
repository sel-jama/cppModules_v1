/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:01:28 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 14:01:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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