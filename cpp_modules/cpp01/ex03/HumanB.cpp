
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_weapon = NULL;
	this->_name = name;

}


HumanB::~HumanB(){}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType
		() << std::endl;
	else
		std::cout << this->_name << " attacks without weapon " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}