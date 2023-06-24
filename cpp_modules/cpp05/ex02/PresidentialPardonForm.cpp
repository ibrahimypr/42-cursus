#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target(""){
    std::cout<<"Constructer calling for PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5){
    std::cout<<"Constructer with parameter calling for PresidentialPardonForm"<<std::endl;
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout<<"Deconstructer calling for PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src){
    std::cout<<"PresidentialPardonForm copy constructer"<<std::endl;
    this->_target = src._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
    std::cout<<"PresidentialPardonForm copy assignment operator called"<<std::endl;
    if(this != &src)
        this->_target = src._target;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(){
    return this->_target;
}

void PresidentialPardonForm::setTarget(std::string target){
    this->_target = target;
}

void PresidentialPardonForm::execute(const Bureaucrat& exe) const{
    if (!(this->getIsSigned()))
        throw NotSignedException();
    else if (exe.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    
    std::cout<<this->_target << " has been pardoned from" << " Zaphod Beeblebrox :(" << std::endl;
}