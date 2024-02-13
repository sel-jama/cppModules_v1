/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:38:23 by sel-jama          #+#    #+#             */
/*   Updated: 2024/02/13 12:39:13 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void addOne(T &num){
    num += 1;
}

template <typename T>
void printElements(T &item){
    std::cout << item << std::endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    unsigned int len = 5;

    iter(arr, len, addOne);
    iter(arr, len, printElements<int>);

}