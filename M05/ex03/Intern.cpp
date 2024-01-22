/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:24:11 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 14:03:09 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
    *this = other;
}

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return (*this);
}

Intern::~Intern(){}

Form *Intern::makeform(const std::string &formName, const std::string &formTarget) const{
    std::string forms[3] = {"ShurbberyCreationForm", "RobotomyRequestForm", "PrsidentilaPardonForm"};
    int formId = -1;
    
    for (int i=0; i < 3; i++){ 
        if (forms[i] == formName)
            formId = i;}
    
    switch (formId)
    {
        case 0:
            return new ShurbberyCreationForm();
        case 1:
            return new RobotomyRequestForm();
        case 2:
            return new PrsidentilaPardonForm();
    
    default:
        break;
    }
}