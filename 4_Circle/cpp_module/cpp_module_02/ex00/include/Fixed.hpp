#ifndef FIXED_HPP_
# define FIXED_HPP_

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

	Fixed &operator=(const Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

#endif