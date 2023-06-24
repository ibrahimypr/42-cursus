#include "Form.hpp"

Form::Form() : _grade_sign(0), _grade_exec(0) { }

Form::~Form() { }

Form::Form(const std::string& name, const int& grade_sign, const int& grade_exec)
	: _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& f) : _name(f.getName()), _signed(false), _grade_sign(f.getGradeSign()), _grade_exec(f.getGradeExec())
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
    {
        *const_cast<std::string*>(&_name) = f.getName();
		*const_cast<int*>(&_grade_exec) = f.getGradeExec();
		*const_cast<int*>(&_grade_sign) = f.getGradeSign();
        _signed = f.getSigned();
    }
    return *this;
}

// Getter
const std::string Form::getName(void) const { return _name; }
bool Form::getSigned(void) const { return _signed; }
int Form::getGradeSign(void) const { return _grade_sign; }
int Form::getGradeExec(void) const { return _grade_exec; }

// Publics
void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() > _grade_sign)
        throw GradeTooLowException();
    if(_signed == true)
        throw AlreadySignedException();
    _signed = true;
}

const char* Form::GradeTooHighException::what(void) const throw() { return "Your grade too high."; }

const char* Form::GradeTooLowException::what(void) const throw() { return "Your grade too low."; }

const char* Form::NotSignedException::what(void) const throw() { return "Your form not signed."; }

const char* Form::FileErrorException::what(void) const throw() { return "File error."; }

const char* Form::AlreadySignedException::what(void) const throw() { return "Your already signed form."; }

// çıkış değeri
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << std::endl
	<< "Sign grade : " << f.getGradeSign() << std::endl
	<< "Execute grade : " << f.getGradeExec() << std::endl
	<<  "Signed : " << std::boolalpha << f.getSigned();
	return os;
}