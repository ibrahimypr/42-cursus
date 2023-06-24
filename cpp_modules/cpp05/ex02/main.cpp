#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 50);
	Bureaucrat b3("b3", 150);
	
	std::cout << "===========ShrubberyCreationForm Success Test===========" << std::endl;
	ShrubberyCreationForm s1("Shrubbery");
	b1.signForm(s1);
	b1.signForm(s1);

	std::cout << std::endl;
	std::cout << s1 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "============ShrubberyCreationForm Fail Test============" << std::endl;
	ShrubberyCreationForm s2("Shrubbery");
	b3.signForm(s2);
	std::cout << std::endl;
	std::cout << s2 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "============RobotomyRequestForm Success Test============" << std::endl;
	RobotomyRequestForm r1("Robotomy");
	b1.signForm(r1);
	b1.executeForm(r1);
	std::cout << std::endl;
	std::cout << r1 << std::endl;
	std::cout << std::endl << std::endl;
/*
	std::cout << "=============RobotomyRequestForm Fail Test=============" << std::endl;
	RobotomyRequestForm r2("Robotomy");
	b2.signForm(r2);
	b2.executeForm(r2);
	std::cout << std::endl;
	std::cout << r2 << std::endl;
	std::cout << std::endl << std::endl;
*/
	std::cout << "===========PresidentialPardonForm Success Test===========" << std::endl;
	PresidentialPardonForm p1("Presidential");
	b1.signForm(p1);
	b1.executeForm(p1);
	std::cout << std::endl;
	std::cout << p1 << std::endl;
	std::cout << std::endl << std::endl;
/*
	std::cout << "============PresidentialPardonForm Fail Test============" << std::endl;
	PresidentialPardonForm p2("Presidential");
	b2.signForm(p2);
	b2.executeForm(p2);
	std::cout << std::endl;
	std::cout << p2 << std::endl;
	std::cout << std::endl << std::endl;
*/
	return 0;
}