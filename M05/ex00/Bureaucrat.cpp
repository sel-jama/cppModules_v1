/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:47:54 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/28 21:32:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name){
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const{
    return (this->name);
}

int Bureaucrat::getGrade() const{
    return (this->grade);
}

std::ostream &operator<<(std::ostream& o, Bureaucrat& b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name){
    if (grade < 1)
        throw (GradeTooHighException());
  
    else if (grade > 150)
        throw (GradeTooLowException());
        
    this->grade = grade;
}

void Bureaucrat::DecrementGrade(){
    if (this->grade >= 150)
        throw (GradeTooLowException());
        
    this->grade++;
}

void Bureaucrat::IncrementGrade(){
    if (this->grade <= 1)
        throw (GradeTooHighException());

    this->grade--;
}