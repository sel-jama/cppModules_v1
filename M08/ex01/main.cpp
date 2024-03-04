#include "Span.hpp"

int main()
{
    try{
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // std::vector<int> v;
        // v.push_back(6);
        // v.push_back(3);
        // v.push_back(17);
        // v.push_back(9);
        // v.push_back(11);
        // sp.addNumbers(v);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    }

    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }


    std::cout << std::endl;
    try {
        Span sp(100000);

        for (int i = 0; i < 100000; ++i) {
            sp.addNumber(i);
        }

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> v1(10); // Create a vector with 10 zeros
        sp.addNumbers(v1);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
