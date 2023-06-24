/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:55:01 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/13 17:10:37 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>

Base*	generate(void)
{
    Base *result;

	srand(time(NULL));
    switch (rand() % 3)
    {
        case 0:
            std::cout << "A created" << std::endl;
            result = new A();
            break;
        case 1:
            std::cout << "B created" << std::endl;
            result = new B();
            break;
        case 2:
            std::cout << "C created" << std::endl;
            result = new C();
            break;
    }
    return(result);
}

void	identify(Base *p){
	std::cout << "p: " << &p << std::endl;
	// eğer ki p nesnesi dynamic_cast ile bir türe dönüştürülemezse geriye nullptr döndürür. P nesnesi A dan referans almıyorsa veya p nesnesi A sınıfına ait bir nesne değilse nullptr döndürür.
	// dynamic_cast operatörü sadece kalıtım ilişkisi olan sınıflar arasında cast işlemi yapabilir.
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "the type is A " << std::endl;
	else if (b)
		std::cout << "the type is B " << std::endl;
	else if (c)
		std::cout << "the type is C " << std::endl;
}

void identify(Base &p){
	// Eğer p nesnesinin gerçek türü A sınıfına dönüştürülemezse, bu işlem std::bad_cast exception atar.
	// Örneğin, p nesnesinin gerçek türü A sınıfının bir alt sınıfı ise, ya da p nesnesi A sınıfına ait bir nesne değil ise, bu işlem exception atar.
	try{
		A &a = dynamic_cast<A &>(p);
		std::cout << "the Type is A" << std::endl;
	}
	catch (std::exception &e) {}

	try{
		B &b = dynamic_cast<B &>(p);
		std::cout << "the Type is B" << std::endl;
	}
	catch (std::exception &e) {}

	try{
		C &c = dynamic_cast<C &>(p);
		std::cout << "the Type is C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main(void)
{
	Base *ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}