

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *tab[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}

	delete tab[0];
	delete tab[1];
	delete tab[2];
	delete tab[3];

	return (0);
}
