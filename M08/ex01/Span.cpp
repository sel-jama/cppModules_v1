#include "Span.hpp"
#include <climits>

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
    if (vec.size() >= maxSize)
        throw fullSpan();

    vec.push_back(toAdd);
}

const char *Span::fullSpan::what() const throw(){
    return "Hehe... Span is full";
}

int Span::longestSpan(){
    std::vector<int>::iterator i;
    std::vector<int>::iterator j;
    int max = 0;

    for (i = vec.begin(); i != vec.end(); ++i){
        for (j = i + 1; j != vec.end(); ++j){
            if (max < *j - *i)
                max = *j - *i;
        }
    }
    return max;
}

int Span::shortestSpan(){
    std::vector<int>::iterator i;
    std::vector<int>::iterator j;
    int min = INT_MAX;

    for (i = vec.begin(); i != vec.end(); ++i){
        for (j = i + 1; j != vec.end(); ++j){
            if (min > abs(*j - *i))
                min = abs(*j - *i);
        }
    }
    return min;
}