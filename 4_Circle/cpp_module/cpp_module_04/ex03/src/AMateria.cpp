#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
: _type(type)
{

}

const std::string &AMateria::getType(void) const
{
	return this->_type;
}