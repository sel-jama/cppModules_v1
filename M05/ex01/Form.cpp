/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:03:08 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 10:08:30 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name(NULL), signGrade(0), executeGrade(0){
    this->isSigned = false;
}

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade)
    : name(name), signGrade(signGrade), executeGrade(executeGrade){
        this->isSigned = false;
}

Form::~Form(){}

Form::Form(const Form& other): name(other.name), signGrade(other.signGrade),
    executeGrade(other.executeGrade){
    *this = other;
}

Form& Form::operator=(const Form& other){
    this->isSigned = other.isSigned;
    return (*this);
}

bool &Form::getIsSigned(void){
    return (this->isSigned);
}

const int &Form::getSignGrade(void) const{
    return (this->signGrade);
}

const int &Form::getExecuteGrade(void) const{
    return (this->executeGrade);
}

const std::string& Form::getName(void) const{
    return (this->name);
}

std::ostream &operator<<(std::ostream &out, Form &f){
    out << "form "<< f.getName() << " of signGrade " << f.getSignGrade()
        << " and executeGrade " << f.getExecuteGrade() << std::endl;
    return (out);
}

void Form::setIsSigned(bool value)
{
    this->isSigned = value;
}

void Form::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
    {
        setIsSigned(true);
        // signForm(b);
    }
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}
