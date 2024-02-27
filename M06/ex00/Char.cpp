/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:01:28 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/27 09:37:25 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printChar(const std::string &str){
	char c = str[0];
	
	std::cout << "char: ";
	std::cout << "'" << c << "'" << std::endl;

	int value = static_cast<int>(c);
	
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}