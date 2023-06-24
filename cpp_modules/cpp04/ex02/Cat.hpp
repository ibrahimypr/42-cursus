

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat(void);
	Cat(Cat const &c);
	virtual ~Cat();
	Cat		&operator = (Cat const &c);
	void	makeSound(void) const;
	Brain	*getBrain() const;
};
