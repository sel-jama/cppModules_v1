/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:24:11 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/23 09:52:10 by sel-jama         ###   ########.fr       */
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

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const{
    std::string forms[3] = {"shurbbery creation", "robotomy request", "prsidentila pardon"};
    int formId = -1;
    
    for (int i=0; i < 3; i++){ 
        if (forms[i] == formName)
            formId = i;}
    
    AForm *ret = NULL;
    switch (formId)
    {
        case 0:
            ret = new ShrubberyCreationForm(formTarget);
            break;
        case 1:
            ret = new RobotomyRequestForm(formTarget);
            break;
        case 2:
            ret = new PresidentialPardonForm(formTarget);
            break;
        default:
            std::cout << "Intern couldn't find form !!" << std::endl;
    }
    if (ret)
        std::cout << "Intern creates " << *ret << std::endl;
    return (ret);
}