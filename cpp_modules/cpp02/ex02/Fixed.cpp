#include "Fixed.hpp"

const int Fixed::_bits = 8;

/*********** CONSTRUCTOR & DESTRUCTOR ***********/
Fixed::Fixed(void) : _value(0)
{ }

Fixed::Fixed(const int value)
{
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _bits)); // float olarak yuvarlama
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
}

Fixed::~Fixed(void)
{ }

/*********** COPY ASSIGNMENT OPERATOR ***********/
Fixed& Fixed::operator=(const Fixed& fix)
{
	_value = fix._value;
	return *this;
}

/*********** COMPARATION OPERATORS ***********/
bool Fixed::operator>(const Fixed &fix) const
{
	return _value > fix.getRawBits();
}

bool Fixed::operator<(const Fixed &fix) const
{
	return _value < fix.getRawBits();
}

bool Fixed::operator>=(const Fixed &fix) const
{
	return _value >= fix.getRawBits();
}

bool Fixed::operator<=(const Fixed &fix) const
{
	return _value <= fix.getRawBits();
}

bool Fixed::operator==(const Fixed &fix) const
{
	return _value == fix.getRawBits();
}

bool Fixed::operator!=(const Fixed &fix) const
{
	return _value != fix.getRawBits();
}

/*********** ARITHMETIC OPERATORS ***********/
Fixed Fixed::operator+(const Fixed &fix) const
{
	return Fixed(this->toFloat() + fix.toFloat());
}

Fixed Fixed::operator-(const Fixed &fix) const
{
	return Fixed(this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(const Fixed &fix) const
{
 return Fixed(this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	return Fixed(this->toFloat() / fix.toFloat());
}

/*********** INCREMENT & DECREMENT ***********/
Fixed& Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed fix(*this);

	_value++;
	return fix;
}

Fixed& Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed fix(*this);

	_value--;
	return fix;
}

/*********** GETTER & SETTER ***********/
int Fixed::getRawBits(void) const
{
	return _value; // private olduğu için erişme işlevi
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}


/*********** MIN & MAX ***********/
Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits()) // getRawBits fatma ablaya sor
		return f1;
	return f2;
}

/*********** TO INT & TO FLOAT ***********/
int Fixed::toInt(void) const
{
	return (_value >> _bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits)); // noktayı (bölü işareti yüzünden) 8 kere sağa kaydırır ve 0 ekleyerek . koymuş oluruz
}

/*********** OSTREAM OPERATOR ***********/
std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return os;
}