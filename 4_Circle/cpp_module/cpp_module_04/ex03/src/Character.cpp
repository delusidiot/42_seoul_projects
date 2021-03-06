#include "Character.hpp"

Character::Character(void): _name(""), _number_equipped(0)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	*this = Character();
	this->_name = name;
}

Character::Character(Character const &src)
{
	*this = src;
}

Character::~Character(void)
{

}

Character &Character::operator=(Character const &rhs)
{
	this->_number_equipped = 0;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i];
		if (rhs._inventory[i])
			this->_number_equipped++;
	}
	this->_name = rhs.getName();
	return *this;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->_number_equipped < Character::_inventory_size)
	{
		this->_inventory[this->_number_equipped] = m;
		this->_number_equipped++;
	}
}

void Character::unequip(int idx)
{
	int i;

	if (idx < 0)
		return;
	i = idx + 1;
	while (i < Character::_inventory_size && this->_inventory[i - 1])
	{
		this->_inventory[i - 1] = this->_inventory[i];
		i++;
	}
	if (i < Character::_inventory_size)
		this->_inventory[i] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= Character::_inventory_size || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

void Character::printInventory(void) const
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			std::cout << i << ": " << this->_inventory[i] << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}