#ifndef POINT_HPP_
# define POINT_HPP_

# include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y; 
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &rhs);
	~Point(void);

	Point	&operator=(const Point &rhs);
	Point	operator-(const Point &rhs) const;
	Fixed	operator*(const Point &rhs) const;

	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Point &instance);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif