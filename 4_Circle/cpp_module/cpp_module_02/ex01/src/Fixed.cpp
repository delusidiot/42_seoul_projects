#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = value << this->_number_of_fractional_bits;
	return;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(value * _fractional_bits_to_int);
	return;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_point_value = rhs._fixed_point_value;
	return *this;
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point_value >> this->_number_of_fractional_bits);
}

float	Fixed::toFloat(void) const
{
	float	result = (float)this->_fixed_point_value / _fractional_bits_to_int;

	return (result);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixed_point_value = raw;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return os;
}