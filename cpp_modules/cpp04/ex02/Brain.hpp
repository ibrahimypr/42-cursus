

#pragma once

#include <iostream>
#include <string>

#define N_IDEAS 100
class Brain
{
private:

public:
	Brain();
	Brain(Brain const & b);
	virtual ~Brain();
	Brain 		&operator=(Brain const & b);
	std::string	ideas[N_IDEAS];
};
