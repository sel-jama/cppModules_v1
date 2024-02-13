/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:48:01 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/29 20:18:46 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    Bureaucrat obj("Smith", 10);
    Bureaucrat obj1("Sam", 1);

    std::cout << "Bureaucrats, represent your selves :" << std::endl;
    std::cout << obj;
    std::cout << obj1;

    std::cout << "Creating a bureaucracts with out of bounds grades :" << std::endl;
    try {
        Bureaucrat obj2("unknown", -1);
    }
    catch(std::exception& exp){
        std::cout << "Couldn't creat bureaucrat because : " << exp.what() << std::endl;
    }

    try {
        Bureaucrat obj2("someone", 151);
    }
    catch(std::exception& exp){
        std::cout << "Couldn't creat bureaucrat because : " << exp.what() << std::endl;
    }

    try{
        Bureaucrat use("test", 150);
        use.DecrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Decrementing failed : " << exp.what() <<std::endl;
    }


    try{
        Bureaucrat use("test", 1);
        use.IncrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Incrementing failed : " << exp.what() <<std::endl;
    }
}