/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:35:27 by sel-jama          #+#    #+#             */
/*   Updated: 2024/03/08 03:45:10 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other){
    *this = other;
}

RPN &RPN::operator=(const RPN &other){
    this->stk = other.stk;
    return *this;
}

RPN::~RPN(){}

bool isnum(const std::string &str){
    if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
        return true;
    return false;
}

bool isopp(const std::string &str){
    if(str.length() == 1 && (str[0] == '*' || str[0] == '+' 
        || str[0] == '-' || str[0] == '/'))
        return true;
    return false;
}

int calcuteOpp(char &opp, int &a, int &b){
    switch (opp)
    {
        case ('*'):         
            return b*a;
        case ('+'):
            return b+a;
        case ('-'):
            return b-a;
        case ('/'):
            if (b != 0)
                return b/a;
        default:
            throw std::invalid_argument("Error.");
    }
}

const std::stack<int> &RPN::getStk(void) const{
    return this->stk;
}

void RPN::calculateValue(const std::string& str){
    std::stringstream ss(str);
    std::string portion;

    while(getline(ss, portion, ' ')){
        int num = 0;
        if(isnum(portion)){
            sscanf(portion.c_str(), "%d", &num);
            stk.push(num);
        }
        else if (isopp(portion) && stk.size() >= 2){
            int element1 = stk.top();
            stk.pop();
            int element2 = stk.top();
            stk.pop();
            try{
                int res = calcuteOpp(portion[0], element1, element2);
                stk.push(res);
            }
            catch(std::invalid_argument &e){
                std::cerr << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else {
            std::cerr << "Error" << std::endl; 
            exit(EXIT_FAILURE);
        }
    }
} 