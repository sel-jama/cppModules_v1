/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:47:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/27 11:58:54 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat{

    private:
        const std::string name;
        int grade;
    
    public:
        const std::string& getName() const;
        int getGrade() const;

        void DecrementGrade();
        void IncrementGrade();

        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
    
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, Bureaucrat& b);

#endif