/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:42:44 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/29 21:49:15 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test(){
	AForm	*form;
	
	std::cout << "Sign and execute a form :" << std::endl;
	
	Bureaucrat	Luis("Luis", 4);
	form = new PresidentialPardonForm("tar1");
	Luis.signForm(*form);
	form->execute(Luis);
	delete form;
	form = NULL;
	
	
	std::cout << "\nExecute a form without signing :" << std::endl;
	
	Bureaucrat		Sam("Sam", 1);
	form = new PresidentialPardonForm("tar2");
	form->execute(Sam);
	delete form;
	form = NULL;

	std::cout << "\nExecute form with unaccredited bureaucrat then a credited one :" << std::endl;
	
	Bureaucrat David("David", 145);
	form = new ShrubberyCreationForm("tar3");
	David.signForm(*form);
	David.executeForm(*form);
	Sam.executeForm(*form);
	delete form;
	form = NULL;
	
	std::cout << "\nsign and execute form :" << std::endl;
	
	form = new RobotomyRequestForm("tar4");
	Sam.signForm(*form);
	Luis.executeForm(*form);
	delete form;
	form = NULL;
}

int main()
{
	test();

	// while(1);
	return 0;
}
