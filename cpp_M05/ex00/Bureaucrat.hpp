
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat{

    private:
        const std::string name;
        int grade;
    
    public:
        // static GradeTooHighException();
        // static GradeTooLowException();
        const std::string& getName() const;
        int getGrade() const;


        void DecrementGrade();
        void IncrementGrade();

        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
    private:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, Bureaucrat& b);

#endif