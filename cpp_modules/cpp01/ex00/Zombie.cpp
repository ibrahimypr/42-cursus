
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << this->name << "-> was created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << "-> was destroyed" << std::endl;
}

void Zombie::announce(){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}