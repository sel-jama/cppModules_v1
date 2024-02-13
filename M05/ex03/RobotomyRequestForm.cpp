/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:07:29 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/29 22:14:54 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request", 72, 45), target(""){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("robotomy request", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other){
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
    srand(std::time(NULL));
    try{
        AForm::executeAction(executor);
    }
    catch(std::exception &e)
    {
        std::cerr << executor.getName() << " couldn't execute form because " << e.what() << std::endl;
        return ;
    }

    std::cout << "Making drilling noises..." << std::endl;

    if (rand() % 2 == 0){
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    }else{
        std::cerr << "Robotomization failed for " << target << std::endl;
    }
}
