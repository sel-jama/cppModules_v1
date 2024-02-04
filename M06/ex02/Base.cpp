/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:28:00 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/04 06:20:15 by sel-jama         ###   ########.fr       */
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
        return &A();
    case 2:
        return &B();
    case 3:
        return &C();
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
    
    try{
        if (id1 != nullptr)
            throw id1;
        if (id2 != nullptr)
            throw id2;
        throw id3;
    }
    catch(Base *id){
        std::cout << id << std::endl;
    }
}

void identify(Base& p){
    try{
        A &id1 = dynamic_cast<A&>(p);
        std::cout << &id1 << std::endl;
    }
    catch(std::exception &e){
        try{
            B &id2 = dynamic_cast<B&>(p);
            std::cout << &id2 << std::endl;
        }
        catch(std::exception &e){
            try{
                C &id3 = dynamic_cast<C&>(p);
                std::cout << &id3 << std::endl;
            }
            catch(std::exception &e){
                std::cout << e.what() << std::endl;
            }
        }
    }
}