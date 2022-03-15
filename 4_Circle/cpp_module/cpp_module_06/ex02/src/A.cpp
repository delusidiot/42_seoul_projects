#include "A.hpp"

A::A(void)
{
}

A::A(A const &src)
{
	*this = src;
}

A::~A(void)
{
}

A &A::operator=(A const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &os, A const &instance)
{
	(void)instance;
	os << "No value for A" << std::endl;
	return os;
}
