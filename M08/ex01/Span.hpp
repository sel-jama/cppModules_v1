#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span {
    private:
        Span();
        unsigned int maxSize;
        std::vector<int> vec;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int toAdd);
        int shortestSpan();
        int longestSpan();

        class fullSpan : public std::exception{
            public:
                const char *what() const throw();
        };

        class TooMany : public std::exception{
            public:
                const char *what() const throw();
        };

        class NoSpan : public std::exception {
            public:
                const char *what() const throw();
        };

        void addNumbers(std::vector<int> v);

};

#endif