

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	FragTrapA("People1");
	FragTrap	FragTrapB("People2");

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapA.attack("People1");
	FragTrapB.takeDamage(FragTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
