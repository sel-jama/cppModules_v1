/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:29:52 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/16 16:09:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array {
    private:
        unsigned int Arraysize;
        T *array;
    public:
        Array();//empty array creation
        Array(unsigned int n); //n elements array creation
        ~Array();

        //deep copy
        Array(const Array& original);
        const Array& operator=(const Array& original);
        int &operator[](const unsigned int &index);

        const unsigned int &size();
        
        class OutOfBounds : public std::exception{
            public:
                const char* what() const throw(){
                    return "The given index is out of bounds ..";
                }
        };
};

template <class T>
Array<T>::Array():array(NULL), Arraysize(0){}

template <class T>
Array<T>::Array(unsigned int n): Arraysize(n){
    this->array = new T[n];
}

template <class T>
Array<T>::Array(const Array& original){
    *this = original;
}

template <class T>
const Array<T> &Array<T>::operator=(const Array<T> &original){
    this->Arraysize = original.Arraysize;
    this->array = new T[Arraysize];
    for (unsigned int i =0; i < Arraysize; i++){
        this->array[i] = original.array[i];
    }
    return *this;
}

template <class T>
int &Array<T>::operator[](const unsigned int &index){
    if (index >= this->Arraysize || this->array == NULL)
        throw OutOfBounds();
    return this->array[index];
}

template <class T>
const unsigned int &Array<T>::size(){
    return this->Arraysize;
}

template <class T>
Array<T>::~Array(){
    // delete[] array;
}

#endif