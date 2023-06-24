#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;

	std::cout << "===========ShrubberyCreationForm Creation Test===========" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout<<"\n test:"<<rrf->getName()<<std::endl;
	delete rrf;
	std::cout << std::endl;

	std::cout << "============RobotomyRequestForm Creation Test============" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	std::cout << std::endl;

	std::cout << "===========PresidentialPardonForm Creation Test===========" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	delete rrf;
	std::cout << std::endl;

	std::cout << "===============UndefinedForm Creation Test===============" << std::endl;
	rrf = someRandomIntern.makeForm("undefined", "Bender");
	delete rrf;
	std::cout << std::endl;
	
	return 0;
}