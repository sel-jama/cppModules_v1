/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:24:11 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/20 00:35:46 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
    *this = other;
}

Intern& operator=(const Intern& other){
    (void)other;
    return (*this);
}

Intern::~Intern(){}

Form *Intern::makeform(std::string &formName, std::string &formTarget){
    std::cout << "Intern Creats" << *this << std::endl;
    return (*this);
}