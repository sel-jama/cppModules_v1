#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class NoOccurrence : public std::exception {
    public:
        const char* what() const throw();
};

const char *NoOccurrence::what() const throw(){
    return "No occurence found!!";
}

template <typename container>
typename container::iterator easyfind(container &param1, int param2){
    typename container::iterator it;
    
    for (it = param1.begin(); it != param1.end(); it++){
        if (*it == param2){
            std::cout << "value found: ";
            return it;
        }
    }
    throw NoOccurrence();
}

#endif
