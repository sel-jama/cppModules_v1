/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:44:40 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/18 01:05:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Bureaucrat.hpp"

class Form : public Bureaucrat 
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
        void    setIsSigned(bool value);
        bool    &getIsSigned(void);
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;

        void    beSigned(Bureaucrat &b);

        void    signForm(Bureaucrat &b);
};

//overload insertion
std::ostream &operator<<(std::ostream &out, Form &f);

#endif