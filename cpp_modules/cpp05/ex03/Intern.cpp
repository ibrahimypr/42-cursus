#include "Intern.hpp"

Intern::Intern(){
    std::cout<<"Constructer calling from Intern class"<<std::endl;
}

Intern::~Intern(){
    std::cout<<"Deconstructer calling from Intern class"<<std::endl;
}

Intern::Intern(const Intern &intern){
    (*this) = intern;
    std::cout<<"Copy constructer for Intern class"<<std::endl;
}

Intern &Intern::operator=(const Intern &src){
    (void)src;
    return *this;
}

AForm *Intern::newPPForm(std::string target){
    return new PresidentialPardonForm(target);
}

AForm *Intern::newRRForm(std::string target){
    return new RobotomyRequestForm(target);
}

AForm *Intern::newSCForm(std::string target){
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target){
    std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*func[])(std::string target) = {
        &Intern::newPPForm,
        &Intern::newRRForm,
        &Intern::newSCForm
    };
    int i = -1;
    while(i++ < 3){
        if (name == forms[i]){
            return (this->*func[i])(target);
        }
    }
        std::cout << "Intern cannot create a form " << name << std::endl;
        return NULL;
}