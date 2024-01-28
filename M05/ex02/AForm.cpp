/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:11:08 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/28 16:34:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name(""), signGrade(0), executeGrade(0){
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

const bool &AForm::getIsSigned(void) const{
    return (this->isSigned);
}

const int &AForm::getSignGrade(void) const{
    return (this->signGrade);
}

const int &AForm::getExecuteGrade(void) const{
    return (this->executeGrade);
}

std::ostream &operator<<(std::ostream &out,const AForm &f){
    out << "Form " << f.getName() << " of signGrade " << f.getSignGrade()
        << " and executeGrade " << f.getExecuteGrade() << std::endl;
    return (out);
}

void AForm::setIsSigned(bool value){
    this->isSigned = value;
}

const std::string& AForm::getName(void) const{
    return (this->name);
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

const char *AForm::IsSignedException::what() const throw(){
    return "Form is not signed ...";
}

void AForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
        setIsSigned(true);
    else
        throw GradeTooLowException();
}

void AForm::executeAction(Bureaucrat const & executor) const{
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    if (getIsSigned() == false)
        throw IsSignedException();
}
