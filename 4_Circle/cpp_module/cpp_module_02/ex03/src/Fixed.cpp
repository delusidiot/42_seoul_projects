#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_value(0)
{
}

Fixed::Fixed(const int value)
{
	this->_fixed_point_value = value << this->_number_of_fractional_bits;
}

Fixed::Fixed(const float value)
{
	this->_fixed_point_value = roundf(value * _fractional_bits_to_int);
}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_fixed_point_value = rhs._fixed_point_value;
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return rhs > *this;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return !(*this < rhs);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return !(*this > rhs);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return rhs.getRawBits() == this->getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return !(rhs == *this);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	old(*this);

	++(*this);
	return old;
}

Fixed &Fixed::operator--(void)
{
	this->_fixed_point_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed	old(*this);

	--(*this);
	return old;
}

bool Fixed::operator~(void) const
{
	return this->getRawBits() > 0;
}

int	Fixed::toInt(void) const
{
	return this->_fixed_point_value >> this->_number_of_fractional_bits;
}

float Fixed::toFloat(void) const
{
	float	result = (float)this->_fixed_point_value / _fractional_bits_to_int;

	return result;
}

int	Fixed::getRawBits(void) const
{
	return this->_fixed_point_value;
}

void Fixed::setRawBits(const int raw)
{
	this->_fixed_point_value = raw;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

std::ostream &operator<<(std::ostream &os, Fixed const &instance)
{
	os << instance.toFloat();
	return os;
}