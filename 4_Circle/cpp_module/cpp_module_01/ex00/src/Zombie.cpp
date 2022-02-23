#include "Zombie.hpp"

Zombie::Zombie(std::string const name)
	: _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "<" << this->_name << "> " << "is died." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) const
{
	return this->_name;
}