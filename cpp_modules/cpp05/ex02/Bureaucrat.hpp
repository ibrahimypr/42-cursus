#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        virtual ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        Bureaucrat operator ++ ();
        Bureaucrat operator -- ();

        std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incBureac(int i);
        void decBureac(int d);
        void incGrade();
        void decGrade();
  
        void executeForm(const AForm & AForm) const;
        void signForm(AForm &AForm) const;
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeFormException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& src);

#endif