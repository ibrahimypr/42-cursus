#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private :
	int _value;
	static const int _bits;
public :
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fix);
	~Fixed(void);
	
	Fixed& operator=(const Fixed &fix);
	bool operator>(const Fixed &fix) const;
	bool operator<(const Fixed &fix) const;
	bool operator>=(const Fixed &fix) const;
	bool operator<=(const Fixed &fix) const;
	bool operator==(const Fixed &fix) const;
	bool operator!=(const Fixed &fix) const;
	Fixed operator+(const Fixed &fix) const;
	Fixed operator-(const Fixed &fix) const;
	Fixed operator*(const Fixed &fix) const;
	Fixed operator/(const Fixed &fix) const;
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static Fixed& max(Fixed &f1, Fixed &f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif
