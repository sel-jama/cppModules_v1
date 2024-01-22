/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:10:51 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 13:49:50 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShurbberyCreationForm", 145, 137), target(""){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShurbberyCreattionForm", 145, 137), target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    this->target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::setTarget(std::string const &tar){
    this->target = tar;
}

const std::string &ShrubberyCreationForm::getTarget(void) const{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    try{
        AForm::execute(executor);
    }
    catch(std::exception &e){
        std::cerr << executor.getName() << " couldn't execute form because " << e.what() << std::endl;
        return ;
    }
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename);
    
    if (!file)
        std::cerr << "Failed to open file " << std::endl;
    else{
        file << "ASCII trees inside it.\n";
        file.close();
        std::cout << "Shurbbery Creation Form done successfully" << std::endl;
    }
}

void ShrubberyCreationForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
        setIsSigned(true);
    else
        throw GradeTooLowException();
}