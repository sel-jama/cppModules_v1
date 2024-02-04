/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:20:19 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/02 04:15:44 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other){
    *this = other;
}

Serializer Serializer::operator=(const Serializer &other){
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
    return uintptr_t(ptr);
}

Data *Serializer::deserialize(uintptr_t raw){
    return (Data *)raw;
}