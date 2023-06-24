
#pragma once

 #include "WrongAnimal.hpp"

 class WrongCat : public WrongAnimal
 {
 public:
	WrongCat(void);
	WrongCat(WrongCat const &wc);
	virtual ~WrongCat();
	WrongCat	&operator = (WrongCat const &wc);
	void		makeSound(void) const;
};
