#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
private:
	static const int	_number_of_fractional_bits = 8;
	static const int	_fractional_bits_to_int = 256;
	static bool			_verbose;
	int					_fixed_point_value;
public:
	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed &src );
	~Fixed( void );

	Fixed	&operator=( const Fixed &rhs );
	bool	operator>( const Fixed &rhs ) const ;
	bool	operator<( const Fixed &rhs ) const ;
	bool	operator>=( const Fixed &rhs ) const ;
	bool	operator<=( const Fixed &rhs ) const ;
	bool	operator==( const Fixed &rhs ) const ;
	bool	operator!=( const Fixed &rhs ) const ;
	Fixed	operator+( const Fixed &rhs ) const ;
	Fixed	operator-( const Fixed &rhs ) const ;
	Fixed	operator*( const Fixed &rhs ) const ;
	Fixed	operator/( const Fixed &rhs ) const ;
	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	int		toInt( void ) const;
	float	toFloat( void ) const;

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

	static Fixed		&min( Fixed &lhs, Fixed &rhs );
	static const Fixed	&min( const Fixed &lhs, const Fixed &rhs );
	static Fixed		&max( Fixed &lhs, Fixed &rhs );
	static const Fixed	&max( const Fixed &lhs, const Fixed &rhs );

	static void	setVerbose( bool value );
	static bool	getVerbose( void );
};

std::ostream	&operator<<( std::ostream &ostream, const Fixed &myClass );

#endif