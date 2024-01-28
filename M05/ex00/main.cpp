/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:48:01 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/27 12:09:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    Bureaucrat obj("smith", 10);
    Bureaucrat obj1("sam", 1);

    std::cout << "Bureaucrats, represent your selves :" << std::endl;
    std::cout << obj;
    std::cout << obj1;

    try {
        Bureaucrat obj2("unknown", -1);
    }
    catch(std::exception& exp){
        std::cout << exp.what() << std::endl;
    }

    try {
        Bureaucrat obj2("someone", 151);
    }
    catch(std::exception& exp){
        std::cout << exp.what() << std::endl;
    }

    try{
        Bureaucrat use("test", 150);
        use.DecrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Decrementing failed :" << std::endl;
        std::cout << exp.what() <<std::endl;
    }

    try{
        Bureaucrat use("test", 1);
        use.IncrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Incrementing failed :" << std::endl;
        std::cout << exp.what() <<std::endl;
    }
}