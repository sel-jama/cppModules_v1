#include "Bureaucrat.hpp"

int main(){
    Bureaucrat obj("smith", 10);
    Bureaucrat obj1("sam", 1);

    std::cout << "Bureaucrats, represent your selves :" << std::endl;
    std::cout << obj;
    std::cout << obj1;

    try {
        Bureaucrat obj2("unknown", -1);
    }
    catch(std::exception& exp){
        std::cout << exp.what() << std::endl;
    }

    try {
        Bureaucrat obj2("someone", 151);
    }
    catch(std::exception& exp){
        std::cout << exp.what() << std::endl;
    }

    try{
        Bureaucrat use("test", 150);
        use.DecrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Decrementing failed >>" << std::endl;
        std::cout << exp.what() <<std::endl;
    }

    try{
        Bureaucrat use("test", 1);
        use.IncrementGrade();
    }
    catch(std::exception& exp){
        std::cout << "Incrementing failed >>" << std::endl;
        std::cout << exp.what() <<std::endl;
    }
}