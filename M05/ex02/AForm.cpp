/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:11:08 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/19 23:11:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name(NULL), signGrade(0), executeGrade(0){
    this->isSigned = false;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &executeGrade)
    : name(name), signGrade(signGrade), executeGrade(executeGrade){
        this->isSigned = false;
}

AForm::~AForm(){}

AForm::AForm(const AForm& other): name(other.name), signGrade(other.signGrade),
    executeGrade(other.executeGrade){
    *this = other;
}

AForm& AForm::operator=(const AForm& other){
    this->isSigned = other.isSigned;
    return (*this);
}

bool &AForm::getIsSigned(void){
    return (this->isSigned);
}

const int &AForm::getSignGrade(void) const{
    return (this->signGrade);
}

const int &AForm::getExecuteGrade(void) const{
    return (this->executeGrade);
}

std::ostream &operator<<(std::ostream &out, AForm &f){
    out << "Form of signGrade " << f.getSignGrade()
        << " and executeGrade " << f.getExecuteGrade() << std::endl;
    return (out);
}

void AForm::setIsSigned(bool value){
    this->isSigned = value;
}

void AForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > getSignGrade())
        throw GradeTooLowException();
}
