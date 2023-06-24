

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog:		Default Constructed" << std::endl;
	this->setType("Dog");
	this->brain = new Brain();
}

Dog::Dog(Dog const &d)
{
	std::cout << "Dog:		Copy Constructed" << std::endl;
	this->brain = new Brain();
	*this = d;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog:		Deleted..." << std::endl;
}

Dog& Dog::operator = (Dog const &d)
{
	std::cout << "Dog:		Assigned." << std::endl;
	this->setType(d.getType());
	*(this->brain) = *(d.brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog:		Hav Hav" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}
