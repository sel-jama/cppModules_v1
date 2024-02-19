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

        void addNumber(int toAdd);
        int shortestSpan();
        int longestSpan();

        class fullSpan : public std::exception{
            public:
                const char *what() const throw();
        };
};

//    template<typename InputIterator>
//     void addNumbers(InputIterator first, InputIterator last) {
//         unsigned int count = std::distance(first, last);
//         if (numbers.size() + count > max_size) {
//             throw std::runtime_error("Adding too many numbers exceeds Span capacity");
//         }
//         numbers.insert(numbers.end(), first, last);
//     }

#endif