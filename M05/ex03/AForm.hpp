/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:42:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/22 10:53:01 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        AForm();
        AForm(const std::string &name, const int &signGrade, const int &executeGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        //getters and setters
        void    setIsSigned(bool value);
        const bool    &getIsSigned(void) const;
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;
        const std::string& getName(void) const;

        void    beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual const std::string &getTarget(void) const = 0;
        void executeAction(Bureaucrat const & executor) const;

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
};

//overload insertion
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif