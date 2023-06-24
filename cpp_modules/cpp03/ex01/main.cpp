
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	ScavTrapA("People1");
	ScavTrap	ScavTrapB("People2");

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapA.attack("People1");
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.guardGate();

	std::cout << std::endl;

	return (0);
}
