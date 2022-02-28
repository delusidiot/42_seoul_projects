#include <cmath>
#include "Fixed.hpp"

bool	Fixed::_verbose = false;

Fixed::Fixed( void ): _fixed_point_value(0)
{
	if (Fixed::_verbose)
		std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const int value )
{
	if (Fixed::_verbose)
		std::cout << "Constant integer constructor called" << std::endl;
	this->_fixed_point_value = value << this->_number_of_fractional_bits;
	return;
}

Fixed::Fixed( const float value )
{
	if (Fixed::_verbose)
		std::cout << "Constant float constructor called" << std::endl;
	this->_fixed_point_value = roundf(value * _fractional_bits_to_int);
	return;
}

Fixed::Fixed( Fixed const & src )
{
	if (Fixed::_verbose)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void )
{
	if (Fixed::_verbose)
		std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	if (Fixed::_verbose)
		std::cout << "Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_point_value = rhs._fixed_point_value;
	return *this;
}

bool	Fixed::operator>( const Fixed &rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<( const Fixed &rhs ) const
{
	return (rhs > *this);
}

bool	Fixed::operator>=( const Fixed &rhs ) const
{
	return (!(*this < rhs));
}

bool	Fixed::operator<=( const Fixed &rhs ) const
{
	return (!(*this > rhs));
}

bool	Fixed::operator==( const Fixed &rhs ) const
{
	return (rhs.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=( const Fixed &rhs ) const
{
	return (!(rhs == *this));
}

Fixed	Fixed::operator+( const Fixed &rhs ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &rhs ) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*( const Fixed &rhs ) const
{
	Fixed	result(this->toFloat() * rhs.toFloat());

	return (result);
}

Fixed	Fixed::operator/( const Fixed &rhs ) const
{
	Fixed	result(this->toFloat() / rhs.toFloat());

	return (result);
}

Fixed	&Fixed::operator++( void )
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old(*this);

	--(*this);
	return (old);
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed_point_value >> this->_number_of_fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	float	result = (float)this->_fixed_point_value / _fractional_bits_to_int;

	return (result);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits( const int raw )
{
	this->_fixed_point_value = raw;
}

void	Fixed::setVerbose( bool value )
{
	Fixed::_verbose = value;
}

bool	Fixed::getVerbose( void )
{
	return (Fixed::_verbose);
}

Fixed		&Fixed::min( Fixed &lhs, Fixed &rhs )
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed		&Fixed::min( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed		&Fixed::max( Fixed &lhs, Fixed &rhs )
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed		&Fixed::max( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

std::ostream &	operator<<( std::ostream & ostr, Fixed const & instance)
{
	ostr << instance.toFloat();
	return (ostr);
}