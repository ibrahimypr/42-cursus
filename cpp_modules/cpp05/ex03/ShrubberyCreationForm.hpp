#ifndef SHURUBBERYCREATIONFORM_HPP
#define SHURUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    private:
        std::string _target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

        std::string getTarget();
        void setTarget(std::string target);

        void execute(const Bureaucrat& exe) const;

};

#endif