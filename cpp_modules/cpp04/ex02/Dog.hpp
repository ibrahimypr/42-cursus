

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog(void);
	Dog(Dog const &d);
	virtual ~Dog();
	Dog		&operator = (Dog const &d);
	void	makeSound(void) const;
	Brain	*getBrain() const;
};
