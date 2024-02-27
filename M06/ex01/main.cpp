/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:07:19 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/26 07:17:29 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){

    Data ptr;
    ptr.grade = 10;
    ptr.student = "Kiven";
    
    std::cout << "Data: Student -> " << Serializer::deserialize(Serializer::serialize(&ptr))->student << std::endl;
    std::cout << "      grade -> " << Serializer::deserialize(Serializer::serialize(&ptr))->grade << std::endl;
}