

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private :
	int _value;
	static const int _bits;
public :
	Fixed(void);
	Fixed(const Fixed &fix);
	~Fixed(void);
	
	Fixed& operator=(const Fixed &fix);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
