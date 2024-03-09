#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid input sequence." << std::endl;
            return 1;
        }
        sequence.push_back(num);
    }

    PmergeMe sorter(sequence);
    sorter.sortAndmesure();

    return 0;
}