/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:33:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 17:59:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

const std::string ScalarConverter::detectType(const std::string &literal)
{
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

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
		return;

	const std::string type = detectType(literal);
	
	if (type == "int")
		printInt(literal);
	else if (type == "char")
		printChar(literal);
	else if (type == "float")
		printFloat(literal);
	else if (type == "double")
		printDouble(literal);
	else
		std::cout << "This type isn't managed in the code! " << std::endl;
}
