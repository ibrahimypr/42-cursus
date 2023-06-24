
#include "Zombie.hpp"

int main()
{
    Zombie *z;
    z = zombieHorde(5, "Zombie");
    delete [] z;
    return 0;
}