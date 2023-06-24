

#include "WrongAnimal.hpp"

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal:	Something Feels Very Wrong " << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &wa)
{
	this->setType(wa.getType()); 
	std::cout << "WrongAnimal:	Assigned." << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	this->setType(wa.getType());
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
}

WrongAnimal::WrongAnimal(void)
{
	this->setType("WrongAnimal");
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal:	Deleted..." << std::endl;
}
