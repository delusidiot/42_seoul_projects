#include "Cure.hpp"

Cure::Cure(void)
: AMateria("cure")
{

}

Cure::Cure(Cure const &src)
: AMateria("cure")
{
	*this = src;
}

Cure::~Cure(void)
{

}

Cure &Cure::operator=(const Cure &rhs)
{
	this->_type = rhs._type;
	return *this;
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
