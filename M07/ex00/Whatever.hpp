/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:17:42 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/01 03:16:47 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b){
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b){
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b){
    if (a > b)
        return a;
    return b;
}


#endif