#ifndef EX00_FIXED_HPP_
# define EX00_FIXED_HPP_

# include <iostream>

class Fixed
{
private:
	static const int _number_of_fractional_bits = 8;
	int _fixed_point_value;
public:
	Fixed(void);
	Fixed(const Fixed &src);
	~Fixed(void);

	Fixed &operator=( const Fixed &other );

	int getRawBits( void ) const;
	void setRawBits( const int raw );
};

#endif //FIXED_HPP_