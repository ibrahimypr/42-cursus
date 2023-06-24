#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target(""){
    std::cout<<"Constructer calling for RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout<<"Constructer with paramether calling for RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout<<"Deconstructer calling for RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
    AForm(src.getName(), src.getGradeSigned(), src.getGradeExecute()), _target(src._target){
        std::cout<< "Copy consturacter calling for RobotomyRequestForm"<<std::endl;    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
    std::cout<< "Copy assignment operator calling for RobotomyRequestForm"<<std::endl;
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

std::string RobotomyRequestForm::getTarget(){
    return this->_target;
}

void RobotomyRequestForm::setTarget(std::string target){
    this->_target = target;
}

void RobotomyRequestForm::execute(const Bureaucrat& exe) const{
    static int counter = 0;

    if(!(this->getIsSigned()))
        throw NotSignedException();
    else if (exe.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    std::cout << "Drilling noises!" << std::endl;
    counter++;
    if (counter % 2)
        std::cout<< this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout<< " the robotomy of " << this->_target << " failed!!"<<std::endl;
}