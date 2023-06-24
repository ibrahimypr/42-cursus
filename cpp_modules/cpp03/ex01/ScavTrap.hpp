

#pragma once

#include <string.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	void attack(const std::string &target);
	void guardGate(void) const;

	ScavTrap &operator=(const ScavTrap &s);

	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &s);
	~ScavTrap(void);
};
