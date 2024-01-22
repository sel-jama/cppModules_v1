/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:47:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/21 12:06:48 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <stdexcept>
// #include "Form.hpp"

class Form;

class Bureaucrat{

    private:
        const std::string name;
        int grade;
    
    public:
        // static GradeTooHighException();
        // static GradeTooLowException();
        const std::string& getName() const;
        int getGrade() const;


        void DecrementGrade();
        void IncrementGrade();

        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        
    // private:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream& o, Bureaucrat& b);

#endif