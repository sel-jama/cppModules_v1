/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:44:40 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/29 20:24:11 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool    isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        Form();
        Form(const std::string &name, const int &signGrade, const int &executeGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        //getters
        void    setIsSigned(const bool value);
        bool    &getIsSigned(void);
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;
        const std::string& getName(void) const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class IsSignedException : public std::exception {
            public :
                const char* what() const throw();
        };
        
        void    beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif