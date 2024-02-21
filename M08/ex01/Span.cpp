#include "Span.hpp"
#include <iterator>
#include <algorithm>

Span::Span(unsigned int N): maxSize(N){
}

Span::Span(const Span &other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    this->maxSize = other.maxSize;
    this->vec = other.vec;
    return *this;
}

void Span::addNumber(int toAdd){
    if (vec.size() > maxSize)
        throw fullSpan();

    vec.push_back(toAdd);
}

const char *Span::fullSpan::what() const throw(){
    return "Hehe... Span is full";
}

const char *Span::TooMany::what() const throw(){
    return "Too many numbers, container reached the max value";
}

const char *Span::NoSpan::what() const throw(){
    return "No span found";
}

int Span::longestSpan(){
    if (vec.size() <= 1 || vec.empty())
        throw NoSpan();
    
    std::sort(vec.begin(), vec.end());
    int max = vec[vec.size() - 1] - vec[0];
    return max;
}

int Span::shortestSpan(){
    if (vec.size() <= 1 || vec.empty())
        throw NoSpan();

    int min;    
    std::sort(vec.begin(), vec.end());
    min = vec[1] - vec[0];
    for (size_t i = 2; i < vec.size(); i++){
        if (min > vec[i] - vec[i-1])
            min = vec[i] - vec[i-1];
    }
    return min;
}

void Span::addNumbers(IT first, IT last){
    unsigned int dis = std::distance(first, last);
    if (dis + this->vec.size() > this->maxSize)
        throw TooMany();
    
    vec.insert(vec.end(), first, last);
}