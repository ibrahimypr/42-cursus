

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	virtual Animal	&operator = (const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();

	virtual void 	makeSound() const = 0;
	virtual Brain	*getBrain() const;

	std::string 	getType() const;
	void			setType(const std::string &type);
};
