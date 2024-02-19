#include "easyfind.hpp"
#include <vector>
#include <list>


int main(){

    try{
        std::vector<int> v = {1, 2, 3, 4, 5};

        std::vector<int>::iterator it = easyfind<std::vector<int>>(v, 3);
        std::cout << *it << std::endl;

        std::list<int> lst = {5, 9, 6, 7, 1};
        std::list<int>::iterator it1 = easyfind<std::list<int>>(lst, 0);
        std::cout << *it1 << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}