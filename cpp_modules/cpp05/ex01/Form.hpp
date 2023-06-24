#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool		_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;

public:
	Form(void);
	Form(const std::string name, int signGrade, int execGrade);
	Form(Form const &f);
	~Form();

	Form 		&operator=(Form const &f);

	std::string	getName() const;
	bool		getSignedResult() const;
	void		setSignedResult(bool signedResult);
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	void		beSigned(Bureaucrat const &b);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what()	const throw()
			{
				return ("<Form> Grade is too High.");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what()	const throw()
			{
				return ("<Form> Grade is too Low.");
			}
	};	
};

std::ostream &operator<<(std::ostream &o, Form const &f);
