/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:42:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/19 23:48:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Bureaucrat.hpp"

class AForm : public Bureaucrat 
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
        ~AForm();
        //getters and setters
        void    setIsSigned(bool value);
        bool    &getIsSigned(void);
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;

        virtual void    beSigned(Bureaucrat &b) = 0;
        void execute(Bureaucrat const & executor) const;
};

//overload insertion
std::ostream &operator<<(std::ostream &out, AForm &f);

#endif