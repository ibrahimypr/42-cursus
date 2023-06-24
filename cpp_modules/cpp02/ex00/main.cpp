
#include "Fixed.hpp"

int main()
{
	Fixed a; // default constructor yapıcı
	Fixed b(a); // copy constructor
	Fixed c;

	c = b; // copy assignation

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
