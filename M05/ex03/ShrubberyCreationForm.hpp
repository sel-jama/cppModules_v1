/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:50:25 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/21 10:00:58 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHURBBERYCREATIONFORM_HPP
# define SHURBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        
        void    setTarget(std::string const &tar);
        const std::string &getTarget(void) const;

        void execute(Bureaucrat const &executor) const;
        void    beSigned(Bureaucrat &b);
        
};

#endif


// void Bureaucrat::executeForm(const AForm& form) const {
//     try {
//         form.execute(*this);
//         std::cout << name << " executed " << form.getName() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << name << " failed to execute " << form.getName() << ": " << e.what() << std::endl;
//     }
// }
