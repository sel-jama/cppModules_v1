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
    typename container::iterator it = find(param1.begin(), param1.end(), param2);
    if (it != param1.end()){
        std::cout << "value found: ";
        return it;
    }
    throw NoOccurrence();
}

#endif
