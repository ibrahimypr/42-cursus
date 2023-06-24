

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	std::cout << "Dog:		Default Constructed" << std::endl;
}

Dog::Dog(Dog const &d) : Animal(d)
{
	*this = d;
	std::cout << "Dog:		Copy Constructed" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog:		Deleted..." << std::endl;
}

Dog& Dog::operator = (Dog const &d)
{
	this->setType(d.getType());
	std::cout << "Dog:		Assigned." << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog:		HAV HAV" << std::endl;
}
