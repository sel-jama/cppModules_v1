/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:20:19 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/08 11:59:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
    return uintptr_t(ptr);
}

Data *Serializer::deserialize(uintptr_t raw){
    return (Data *)raw;
}