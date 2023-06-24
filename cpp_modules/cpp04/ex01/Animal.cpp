

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal:		Default Constructed" << std::endl;
	this->setType("Animal");
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal:		Copy Constructed" << std::endl;
	*this = a;
}

Animal::~Animal()
{
	std::cout << "Animal:		Deleted..." << std::endl;
}

Animal&	Animal::operator=(const Animal &a)
{
	std::cout << "Animal:		Assigned." << std::endl;
    if ((this->type == "Cat" || this->type == "Dog") && (a.type == "Cat" || a.type == "Dog"))
        *getBrain() = *a.getBrain();
	this->setType(a.getType());
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal:		???" << std::endl;
}

Brain	*Animal::getBrain(void) const
{
	return (NULL);
}
