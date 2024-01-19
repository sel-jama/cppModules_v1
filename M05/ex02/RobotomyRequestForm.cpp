/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:07:29 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/20 00:15:18 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other){
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    this->target = other.target;
    return (*this);
}

void RobotomyRequestForm::setTarget(std::string const &tar){
    this->target = tar;
}

const std::string &RobotomyRequestForm::getTarget(void) const{
    return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
    try{
        AForm::execute(executor);
    }
    catch(std::exception &e)
    {
        std::cerr << target << " " << e.what() << std::endl;
        return ;
    }

    std::cout << "Making drilling noises..." << std::endl;

    if (rand() % 2 == 0){
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }else{
        std::cerr << "Robotomization failed for " << target << std::endl;
    }
}

void RobotomyRequestForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
        setIsSigned(true);
    else
        throw GradeTooLowException();
}