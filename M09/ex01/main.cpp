/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:35:25 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/07 20:41:54 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[]){
    if (ac != 2){
        std::cerr << "Invalid argument, please try again." << std::endl;
        return 1;
    }
    
    RPN rpn;

    rpn.calculateValue(av[1]);
    if (rpn.getStk().size() != 1)
        std::cerr << "Error: Operation went wrong.." << std::endl;
    else
        std::cout << rpn.getStk().top() << std::endl;
    
    return 0;
}