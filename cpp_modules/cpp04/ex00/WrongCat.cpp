
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->setType("WrongCat");
	std::cout << "WrongCat:	Default Constructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wc) : WrongAnimal(wc)
{
	*this = wc;
	std::cout << "WrongCat:	Copy Constructed" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat:	Deleted..." << std::endl;
}

WrongCat& WrongCat::operator = (WrongCat const &wc)
{
	this->setType(wc.getType());
	std::cout << "WrongCat:	Assigned." << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat:	MOO" << std::endl;
}
