

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &d);
	virtual ~Dog();
	Dog		&operator = (Dog const &d);
	void	makeSound(void) const;
};