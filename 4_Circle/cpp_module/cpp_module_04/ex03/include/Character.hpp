#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	Character(void);
	static const int	_inventory_size = 4;

	std::string	_name;
	AMateria	*_inventory[Character::_inventory_size];
	int			_number_equipped;
public:
	Character(const std::string &name);
	Character(const Character &src);
	~Character(void);

	Character	&operator=(const Character &rhs);

	virtual std::string const	&getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

	virtual void		printInventory(void) const;
};

#endif
