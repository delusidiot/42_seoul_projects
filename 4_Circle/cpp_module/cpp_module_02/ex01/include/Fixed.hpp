#ifndef EX01_FIXED_HPP_
# define EX01_FIXED_HPP_

# include <iostream>
class Fixed
{
private:
	static const int _number_of_fractional_bits = 8;
	static const int _fractional_bits_to_int = 256;
	int _fixed_point_value;
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& src);
	~Fixed(void);

	Fixed&	operator=(const Fixed& other);

	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // EX01_FIXED_HPP_