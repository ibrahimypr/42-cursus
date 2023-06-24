#include "AForm.hpp"


AForm::AForm(): _name("AForm"), _gradeSigned(0), _gradeExecute(0){
    //std::cout<<"Constructer calling from From class"<<std::endl;
    this->_isSigned = false;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute):
    _name(name),
    _isSigned(false),
    _gradeSigned(gradeSign),
    _gradeExecute(gradeExecute){

        if (gradeSign < 1 || gradeExecute < 1)
            throw GradeTooHighException();
        else if (gradeSign > 150 || gradeExecute > 150)
            throw GradeTooLowException();
    //std::cout<<"Constructer calling from AForm class " <<std::endl;
}

AForm::~AForm(){
    //std::cout<<"Deconstructer calling from AForm class"<<std::endl;
}

AForm::AForm(const AForm &src):
    _name(src.getName()),
    _isSigned(src.getIsSigned()),
    _gradeSigned(src.getGradeSigned()),
    _gradeExecute(src.getGradeExecute())
{
    //std::cout<<"AForm copy constructer"<<std::endl;
   if (_gradeSigned < 1 || _gradeExecute < 1)
        throw GradeTooHighException();
    else if (_gradeSigned > 150 || _gradeExecute > 150)
        throw GradeTooLowException();

}

AForm &AForm::operator=(const AForm &src){
    //std::cout<<"AForm copy assignment operator called"<<std::endl;
    if(this != &src)
        this->_isSigned = (&src)->getIsSigned();
    return(*this);
}

std::string AForm::getName() const{
    return this->_name;
}

int AForm::getGradeSigned() const{
    return this->_gradeSigned;
}

int AForm::getGradeExecute() const{
    return this->_gradeExecute;
}

bool AForm::getIsSigned() const{
    return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > this->getGradeSigned()){
        throw GradeTooLowException();
    }
    else if (this->getIsSigned() == 1){
        throw AlreadySignedException();
        return ;
    }
    else{
        this->_isSigned = true;
    }
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("AForm error: GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("AForm error: GradeTooLowException");
}

const char* AForm::AlreadySignedException::what() const throw(){
    return ("AForm error: AlreadySignedException");
}

const char* AForm::NotSignedException::what() const throw(){
    return ("AForm error: NotSignedException");
}

std::ostream& operator<<(std::ostream& stream, const AForm& src){
    std::string msg;

    if (src.getIsSigned())
        msg = "true";
    else
        msg = "false";
    stream << "AForm: " << src.getName() << std::endl << "Signed: " << msg<<std::endl
    << "Grade to sign it: " << src.getGradeSigned() <<std::endl
    << "Grade to execute it: " << src.getGradeExecute()<<std::endl;
    return (stream);
}