/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:48:01 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/20 00:16:04 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    try {
        // Create a Bureaucrat
        Bureaucrat bureaucrat("John Doe", 5);

        // Create a Form
        Form form("Application Form", 6, 4);

        // Try to sign the form
        bureaucrat.signForm(form);

        // Try to sign the form again (this should fail)
        bureaucrat.signForm(form);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
