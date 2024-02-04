/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:22:48 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/02 04:13:56 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct s_data{
    std::string student;
    int grade;
}Data;

class Serializer {
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer operator=(const Serializer &other);
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
};

#endif