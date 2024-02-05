/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:41:18 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/05 02:44:03 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    ScalarConverter scalar;
    if (ac == 2)
        scalar.convert(av[1]);
    else
        std::cout << "Wrong number of argument..." << std::endl;
    
    return 0;
}