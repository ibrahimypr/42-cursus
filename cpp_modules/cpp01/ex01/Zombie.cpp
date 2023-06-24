#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "-> was created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "-> was destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}