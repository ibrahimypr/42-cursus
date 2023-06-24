

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat:	Default Constructed" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &wc) : WrongAnimal(wc)
{
	std::cout << "WrongCat:	Copy Constructed" << std::endl;
	*this = wc;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat:	Deleted..." << std::endl;
}

WrongCat& WrongCat::operator = (WrongCat const &wc)
{
	std::cout << "WrongCat:	Assigned." << std::endl;
	this->setType(wc.getType());
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat:	MOO" << std::endl;
}
