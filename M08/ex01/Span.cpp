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

Span::~Span(){}

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
    
    int max = *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());

    return max;
}

int Span::shortestSpan(){
    if (vec.size() <= 1 || vec.empty())
        throw NoSpan();

    int min, span;
    std::vector<int> v(vec);
    
    std::sort(v.begin(), v.end());
    min = v[1] - v[0];
    for (size_t i = 2; i < v.size(); i++){
        span = v[i] - v[i-1];
        if (min > span)
            min = span;
    }
    return min;
}

void Span::addNumbers(std::vector<int> v){
    std::vector<int>::iterator first = v.begin();
    std::vector<int>::iterator last = v.end();

    unsigned int dis = std::distance(first, last);
    if (dis + this->vec.size() > this->maxSize)
        throw TooMany();
    
    vec.insert(vec.end(), first, last);
}
