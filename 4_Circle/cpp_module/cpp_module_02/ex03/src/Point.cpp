#include "Point.hpp"

Point::Point(void)
:_x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point(const float x, const float y)
:_x(Fixed(x)), _y(Fixed(y))
{

}

Point::~Point(void)
{

}

Point::Point(const Point &rhs)
{
	*this = rhs;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(_x) = rhs.getX();
		const_cast<Fixed&>(_y) = rhs.getY();
	}
	return *this;
}

Point Point::operator-(const Point &rhs) const
{
	return Point((this->getX() - rhs.getX()).toFloat(), (this->getY() - rhs.getY()).toFloat());
}
	

Fixed Point::operator*(const Point &rhs) const
{
	return Fixed((this->getX() * rhs.getY()) - (this->getY() * rhs.getX()));
}

const Fixed& Point::getX(void) const
{
	return _x;
}

const Fixed& Point::getY(void) const
{
	return _y;
}

std::ostream &operator<<(std::ostream &os, const Point &instance)
{
	os << "(" << instance.getX().toFloat() << ", " << instance.getY().toFloat() << ")";
	return os;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed alpha = ((b.getY() - c.getY())*(point.getX() - c.getX()) + (c.getX() - b.getX())*(point.getY() - c.getY())) 
					/ ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	Fixed beta = ((c.getY() - a.getY())*(point.getX() - c.getX()) + (a.getX() - c.getX())*(point.getY() - c.getY()))
					/ ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	Fixed gamma = Fixed(1.0f) - alpha - beta;

	return alpha > 0 && alpha < 1 && beta > 0 && beta < 1 && gamma > 0 && gamma < 1;
}