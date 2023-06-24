#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat f("test1", 4);
        std::cout << f << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("test2", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    try 
	{
        Bureaucrat bureaucrat1("test3", 1);
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cerr << e.what() << std::endl;
    }
    try 
	{
        Bureaucrat bureaucrat2("test4", 150);
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
}