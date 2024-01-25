/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:54:05 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/23 09:54:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern	intern;
	AForm	*f;

	f = intern.makeForm("shurbbery creation", "Bender3");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;

	f = intern.makeForm("robotomy request", "Bender2");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;

	f = intern.makeForm("prsidentila pardon", "Bender1");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;
	
	delete f;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("none", "Bender");
	delete rrf;

	return 0;
}
