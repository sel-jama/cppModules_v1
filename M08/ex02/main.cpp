#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "-------" << std::endl;

    MutantStack<int> mutantStack;
    MutantStack<int> newStk;


    mutantStack.push(10);
    mutantStack.push(20);
    mutantStack.push(30);
    mutantStack.push(40);
    mutantStack.push(50);
    mutantStack.pop();

    newStk.push(1);
    newStk.push(2);
    mutantStack.swap(newStk);

    std::cout << "MutantStack elements: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "newStk elements: ";
    for (MutantStack<int>::iterator it = newStk.begin(); it != newStk.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
