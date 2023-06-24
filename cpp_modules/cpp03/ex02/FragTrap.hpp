

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const name);
	FragTrap(FragTrap const &f);
	FragTrap	&operator = (FragTrap const &b);
	~FragTrap();

	void	highFivesGuys(void);
};
