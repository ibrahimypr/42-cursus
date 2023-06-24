#include "Zombie.hpp"

int main()
{
	Zombie* Foo = newZombie("Foo");
	Foo->announce();
	Zombie* Joo = newZombie("Joo");
	Joo->announce();
	Zombie* Hoo = newZombie("Hoo");
	Hoo->announce();
	randomChump("ZombieChump1");
	randomChump("ZombieChump2");
	randomChump("ZombieChump3");
	delete Foo;
	delete Joo;
	delete Hoo;
	return (0);
}