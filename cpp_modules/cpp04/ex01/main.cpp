
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *tab[4];

	Dog a;
	std::cout << "----------------" << std::endl;
	Dog b(a);
	std::cout << "----------------" << std::endl;

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

	std::cout << "===================================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	return (0);
}
