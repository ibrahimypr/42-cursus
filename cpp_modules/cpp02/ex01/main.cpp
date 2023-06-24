
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10); // değer int olduğunu anlayıp ona göre constructorı çalıştıracak
	Fixed const c(42.42f);
	Fixed const d(b); // copy cons (kopya yapıcı) kullanıldığı yer

	a = Fixed(1234.4321f); // copy assignation (kopya atayıcı) kullanıldığı yer // yeni bir obje oluşturup objeye değeri atayıp geri döndürüp a'ya atıyoruz.

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
