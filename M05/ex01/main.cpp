/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:48:01 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/28 22:39:50 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    try {
        
        Bureaucrat bureaucrat("Sam", 1);
        Form form("Grades form", 4, 2);
        bureaucrat.signForm(form);
        
    } catch (const std::exception& e) {
        std::cerr << "Failed because " << e.what() << std::endl;
    }

    try {

        Bureaucrat bureaucrat("Susan", 10);
        Form form("Contact form", 9, 2);
        bureaucrat.signForm(form);
        
    } catch (const std::exception& e) {
        std::cerr << "Failed because " << e.what() << std::endl;
    }

    try {
        
        Bureaucrat bureaucrat("Steve", 11);
        Form form("Feedback form", 12, 2);
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
        
    } catch (const std::exception& e) {
        std::cerr << "Failed because " << e.what() << std::endl;
    }
    return 0;
}
