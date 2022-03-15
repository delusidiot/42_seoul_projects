#include "B.hpp"

B::B(void)
{
}

B::B(B const &src)
{
	*this = src;
}

B::~B(void)
{
}

B &B::operator=(B const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &os, B const & instance)
{
	(void)instance;
	os << "No value for B" << std::endl;
	return os;
}
