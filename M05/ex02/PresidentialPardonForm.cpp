/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:10:33 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 13:48:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PrsidentilaPardonForm", 25, 5), target(""){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm("PresidentialPardonForm", 25, 5){
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
        AForm::executeAction(executor);
    }
    catch(std::exception &e){
        std::cerr << executor.getName() << " couldn't execute form because " << e.what() << std::endl;
        return ;
    }

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
        setIsSigned(true);
    else
        throw GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}