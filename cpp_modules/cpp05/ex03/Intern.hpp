#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    private:
        AForm *newPPForm(std::string target);
        AForm *newRRForm(std::string target);
        AForm *newSCForm(std::string target);
    public:
        Intern();
        virtual ~Intern();
        Intern(const Intern &intern);
        Intern &operator=(const Intern &src);

        AForm *makeForm(std::string name, std::string target);
};


#endif