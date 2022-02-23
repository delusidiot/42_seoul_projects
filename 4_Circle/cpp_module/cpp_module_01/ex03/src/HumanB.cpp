#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:_name(name), _weapon(nullptr)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack because they don't have a weapon" << std::endl;
}

Weapon& HumanB::getWeapon(void) const
{
	return *(this->_weapon);
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}