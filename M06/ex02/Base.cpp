/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:28:00 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/05 00:34:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void){
    srand(time(NULL));
    int randNUm = rand() % 3 + 1;
    switch (randNUm)
    {
    case 1:
        return new A();
    case 2:
        return new B();
    case 3:
        return new C();
    default:
        std::cout << "Someting went wrong, pleaze try again.." << std::endl;
        break;
    }
    return NULL;
}

void identify(Base* p){
    A *id1;
    B *id2;
    C *id3;

    id1 = dynamic_cast<A*>(p);
    id2 = dynamic_cast<B*>(p);
    id3 = dynamic_cast<C*>(p);
    
    if (id1)
        std::cout << "A";
    else if (id2)
        std::cout << "B";
    else if (id3)
        std::cout << "C";
    else
        std::cout << "Error";

    std::cout << std::endl;
}

void identify(Base& p){
    try{
        A &id1 = dynamic_cast<A&>(p);
        (void)id1;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e){
        try{
            B &id2 = dynamic_cast<B&>(p);
            (void)id2;
            std::cout << "B" << std::endl;
        }
        catch(std::exception &e){
            try{
                C &id3 = dynamic_cast<C&>(p);
                (void)id3;
                std::cout << "C" << std::endl;
            }
            catch(std::exception &e){
                std::cout << e.what() << std::endl;
            }
        }
    }
}