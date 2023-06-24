
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
	std::cout << "WrongAnimal:	Can't make sound Yet " << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &wa)
{
	std::cout << "WrongAnimal:	Assigned." << std::endl;
	this->setType(wa.getType()); 
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
	this->setType(wa.getType());
}

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
	this->setType("WrongAnimal");
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal:	Deleted..." << std::endl;
}
