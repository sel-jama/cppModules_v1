/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:03:08 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/18 01:07:15 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name(NULL), signGrade(0), executeGrade(0){
    // this->isSigned = false;
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

std::ostream &operator<<(std::ostream &out, Form &f){
    out << f.getIsSigned() << std::endl;
    out << f.getSignGrade() << std::endl;
    out << f.getExecuteGrade() << std::endl;
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
        signForm(b);
    }
    else
        throw(GradeTooLowException());
}

void Form::signForm(Bureaucrat &b){
    // Bureaucrat b;
    std::cout << b << "signed " << *this <<std::endl;
}