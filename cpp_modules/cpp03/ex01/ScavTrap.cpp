

#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "ScavTrap:	" << this->_name << ", you already dead" << std::endl;
	else
	{
		std::cout << "ScavTrap:	" << this->_name << " attacks " << target <<
		", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(void) const
{
		std::cout << "ScavTrap:	" << this->_name << " is now in Gate keeper mode."  << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &s)
{
	ClapTrap::operator=(s);
	return(*this);
}

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap:	default constructor has been called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap:	name constructor has been called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	std::cout << "ScavTrap:	copy ConstructoOr has been called" << std::endl;
	*this = s;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap:	destructor has been called" << std::endl;
}
