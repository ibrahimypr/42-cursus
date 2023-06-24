#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
    private:
        std::string _target;
        PresidentialPardonForm();
    
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

        std::string getTarget();
        void setTarget(std::string target);
        
        void execute(const Bureaucrat & exe) const;
};

#endif