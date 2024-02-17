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
        T &operator[](unsigned int index);

        const unsigned int &size();
        
        class OutOfBounds : public std::exception{
            public:
                const char* what() const throw(){
                    return "The given index is out of bounds ..";
                }
        };
};

template <class T>
Array<T>::Array():Arraysize(0){
    this->array = new T[this->Arraysize];
}

template <class T>
Array<T>::Array(unsigned int n): Arraysize(n){
    this->array = new T[n];
}

template <class T>
Array<T>::Array(const Array& original): Arraysize(original.Arraysize){
    this->array = NULL;
    *this = original;
}

template <class T>
const Array<T> &Array<T>::operator=(const Array<T> &original){
    if (this->array)
        delete[] this->array;
    if (original.Arraysize > 0){
        this->Arraysize = original.Arraysize;
        this->array = new T[Arraysize];
        for (unsigned int i = 0; i < Arraysize; i++){
            this->array[i] = original.array[i];
        }
    }
    return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index){
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
    if (this->array)
        delete[] array;
}

#endif