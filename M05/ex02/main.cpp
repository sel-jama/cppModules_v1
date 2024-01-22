/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:47:47 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 13:04:29 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat		Odin("Odin", 1);
	Bureaucrat		Thor("Thor", 40);
	Bureaucrat		Loki("Loki", 150);
	AForm			*form = NULL;

	std::cout << "Let's execute an unsigned presidential pardon form" << std::endl;
	form = new PresidentialPardonForm("28Z");
	form->execute(Odin);
	delete form;
	form = NULL;

	std::cout << "\nLet's sign and execute a presidential pardon form" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28A");
		form->beSigned(Odin);
		form->execute(Odin);
		delete form;
		form = NULL;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's sign and execute robotomy request form with different people" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28B");
		Odin.signForm(*form);
		std::cout << std::endl;
		Thor.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's execute shrubbery creation form with unauthorized bureaucrat" << std::endl;

	form = new ShrubberyCreationForm("28C");
	Odin.signForm(*form);
	Thor.executeForm(*form);
	Loki.executeForm(*form);
	delete form;
	form = NULL;

	return 0;
}