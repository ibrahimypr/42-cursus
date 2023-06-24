#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

#define LOWEST 150
#define HIGHEST 1

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &b);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &b);
		std::string	getName() const;
		int		getGrade() const;
		
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what()	const throw()
				{
					return ("Grade is too High.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what()	const throw()
				{
					return ("Grade is too Low.");
				}
		};
};
std::ostream& operator<<(std::ostream &o, Bureaucrat const &b);
