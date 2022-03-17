#include "AMateria.hpp"

AMateria::AMateria(void)
: _type("")
{

}

AMateria::AMateria(const std::string &type)
: _type(type)
{

}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{

}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs._type;
	return *this;
}

const std::string &AMateria::getType(void) const
{
	return this->_type;
}