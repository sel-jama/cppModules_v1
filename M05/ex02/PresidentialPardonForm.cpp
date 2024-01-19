/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:10:33 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/20 00:14:34 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    this->target = other.target;
    return (*this);
}

void PresidentialPardonForm::setTarget(std::string const &tar){
    this->target = tar;
}

const std::string &PresidentialPardonForm::getTarget(void) const{
    return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    try{
        AForm::execute(executor);
    }
    catch(std::exception &e){
        std::cerr << target << " " << e.what() << std::endl;
        return ;
    }

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
        setIsSigned(true);
    else
        throw GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}