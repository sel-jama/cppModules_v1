/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:29:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/15 15:51:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array {
    private:
        unsigned int size;
        T *array;
    public:
        Array();//empty array creation
        Array(unsigned int n); //n elements array creation

        //deep copy
        Array(const Array& original);
        const Array& operator=(const Array& original);

        const unsigned int &size();
};

template <class T>
Array<T>::Array():array(NULL), size(0){}

template <class T>
Array<T>::Array(unsigned int n): size(n){
    this->array = new T[n];
}

template <class T>
Array<T>::Array(const Array& original){
    *this = original;
}

template <class T>
const Array<T> &Array<T>::operator=(const Array<T> &original){
    this->size = original.size;
    this->array = new T[size];
    for (int i =0; i < size; i++){
        this->array[i] = original.array[i];
    }
}

template <class T>
const unsigned int &Array<T>::size(){
    return this->size;
}

#endif