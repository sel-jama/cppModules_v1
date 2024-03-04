#include "easyfind.hpp"
#include <vector>
#include <list>


int main(){

    try{
        std::vector<int> v;
        for (int i = 0; i < 5; i++){
            v.push_back(i);
        }

        std::vector<int>::iterator it = easyfind<std::vector<int> >(v, 3);
        std::cout << *it << std::endl;

        std::list<int> lst;
        for (int j = 1; j <= 5; j++){
            lst.push_back(j);
        }
        std::list<int>::iterator it1 = easyfind<std::list<int> >(lst, 0);
        std::cout << *it1 << std::endl;

    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

}