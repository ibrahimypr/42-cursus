
#pragma once

#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	int				_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &b);
	~ClapTrap();

	std::string		&getName();
	void			setName(std::string &Name);
	int				&getHitpoints();
	void			setHitpoints(int Hitpoints);
	unsigned int	&getEnergyPoints();
	void			setEnergyPoints(int EnergyPoints);
	unsigned int	&getAttackDamage();
	void			setAttackDamage(int AttackDamage);

	ClapTrap		&operator=(ClapTrap const &b);

	void			attack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};
std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap2);
