#include "C.hpp"

C::C(void)
{
}

C::C(C const &src)
{
	*this = src;
}

C::~C(void)
{
}

C &	C::operator=(C const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &os, C const &instance)
{
	(void)instance;
	os << "No value for C" << std::endl;
	return os;
}
