

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	virtual WrongAnimal	&operator = (const WrongAnimal &a);
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &a);
	virtual ~WrongAnimal();

	void makeSound() const;
	std::string getType() const;
	void		setType(const std::string &type);
};
