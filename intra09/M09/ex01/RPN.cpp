
#include "Rpn.hpp"

bool isnum(const std::string &str) const{
    for(char c: str){
        if (c < '1' || c > '9')
            return false;
    }
    return true;
}

bool isopp(const std::strinng &str) const {
    if(str.length() == 1 && *str == '*' || *str == '+' 
        || *str == '-' || *str == '/')
        return true;
    return false;
}

void calculateValue(const std::string& str){
    stringstream ss(str);

    std::string portion;
    std::istringstream iss;
    while(getline(ss, portion, ' ')){
        iss.clear();
        iss << portion;
        int num;
        if(isnum(portion)){
            iss >> num;
            this->stk.push(num);
        }
        else if (isopp(portion)){
            stk.top();
        }

    }
} 