#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(1){
    //std::cout<<"Constructer calling from Bureaucrat class"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    //std::cout<<"Parameter Constructer calling from Bureaucrat class"<<std::endl;
    //throwlar gelecek buraya

    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
    //std::cout<<"Deconstructer calling from Bureaucrat class"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()), _grade(src.getGrade()){
    //std::cout<<"Bureaucrat copy constructer"<<std::endl;
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src){
    //std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
    if (this != &src)
        this->setGrade(src.getGrade());
    return(*this);
}

Bureaucrat Bureaucrat::operator ++ (){
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->setGrade(this->getGrade() + 1);
    return (*this);
}

Bureaucrat Bureaucrat::operator -- (){
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->setGrade(this->getGrade() - 1);
    return (*this);
}


//get set

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::setGrade(int grade){
    this->_grade = grade;
}



void Bureaucrat::incBureac(int i){
    if (this->getGrade() - i <  1)
        throw GradeTooHighException();
    else
        this->_grade -= i;
}

void Bureaucrat::decBureac(int d){
    if (this->getGrade() + d > 150)
        throw GradeTooLowException();
    else
        this->_grade += d;
}

// increment decrement
void Bureaucrat::incGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::executeForm(const AForm& AForm) const
{
    
    try
    {
        AForm.execute(*this);
        std::cout << this->getName() << " executed " << AForm.getName() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot execute " << AForm.getName() << AForm.getName() << " because " << AForm.getName() << " " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &AForm) const
{
    try
    {
        AForm.beSigned(*this);
        std::cout<< this->getName() << " signed " << AForm.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade can't be higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade can't be lower than 150");
}

const char* Bureaucrat::GradeFormException::what() const throw(){
    return ("Grade is lower than Form grade");
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& src){
    stream<< src.getName() << ", bureaucrat grade " << src.getGrade();
    return (stream);
}