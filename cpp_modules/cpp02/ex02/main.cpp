#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));  // buranın sonucu 10.1 gibi bir şey dönüyor 
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << " b value"<< std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}