/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:02:09 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/27 09:23:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*utils*/

bool isInt(const std::string &str)
{
	const char *s = str.c_str();
	char *n;

	std::strtol(s, &n, 10);
	if (*n == '\0')
		return true;
	return false;
}

bool isChar(const std::string &str)
{
	if (str.length() == 1 && (isalpha(str[0])))
		return true;
	return false;
}

bool isFloat(const std::string &str)
{
	if (str.empty())
		return false;
	if (isPseudo(str))
		return true;

	int count = 0;
	if (str[str.length() - 1] != 'f')
		return false;
	for (unsigned int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] == '.')
			count++;
		else if (i != str.length() - 1 && !isdigit(str[i]))
			return false;
	}
	if (count == 1 && str[0] != '.' && str[str.length() - 2] != '.')
	{
		return true;
	}
	return false;
}

bool isDouble(const std::string &str)
{
	if (str.empty())
		return false;
	if (str == "-inf" || str == "inf" || str == "+inf" || str == "nan")
		return true;

	int count = 0;
	for (unsigned int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] == '.')
			count++;
		else if (!isdigit(str[i]))
			return false;
	}
	if (count == 1 && str[0] != '.' && str[str.length() - 1] != '.')
	{
		return true;
	}
	return false;
}

bool isZero(const char *s)
{
	const char *point = strchr(s, '.');
	if (!point)
		return false;
	point++;
	while ((*point) != '\0')
	{
		if (*point == 'f' && *(point + 1) == '\0')
			return true;
		if (*point != '0')
			return false;
		point++;
	}
	return true;
}

bool isPseudo(const std::string &s){
	if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan" 
		|| s == "inff" || s == "+inff" || s == "-inff" || s == "nanf")
			return true;
	return false;
}

bool ft_isprint(char c){
    return std::isprint(static_cast<unsigned char>(c));
}