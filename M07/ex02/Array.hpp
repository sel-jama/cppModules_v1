/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:29:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/13 13:37:44 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array {
    private:
        T array[];
    public:
        Array(){ array = new T; }//empty array creation
        Array(unsigned int n){ } //n elements array creation
        
        //deep copy
        Array(const Array& original){ *this = original; }
        const Array& operator=(const Array& original) { 
            for(int i = 0; i < original.size(); i++){
                this->array[i] = new array[i];
            }
            return *this;
        }

        const unsigned int &size() const{
            return (sizeof(this->array) / sizeof(T));
        }
};

#endif