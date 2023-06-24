#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSigned;
        const int _gradeExecute;
    public:
        AForm();
        AForm(std::string const name, bool isSigned, const int gradeSigned,const int gradeExecute);
        AForm(std:: string name, int gradeSign, int gradeExecute);
        virtual ~AForm() = 0;
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSigned() const;
        int getGradeExecute() const;

        virtual void execute(const Bureaucrat& exe) const = 0;
        void beSigned(const Bureaucrat& bureaucrat);//Add also a beSigned() member function to the Form that takes a Bureaucrat as
                                                    //parameter.
                
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class AlreadySignedException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class NotSignedException : public std::exception{
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& stream, const AForm& other);


/*
const üye işlevleri, programda sabit olarak bildirilen işlevlerdir.
Bu işlevler tarafından çağrılan nesne değiştirilemez.
Nesnede yanlışlıkla yapılan değişikliklerden kaçınmak için 
const anahtar sözcüğünün kullanılması önerilir.
*/
#endif