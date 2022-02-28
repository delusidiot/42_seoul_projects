#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	int			_initialEnergyPoints;
public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &src);
	virtual ~ClapTrap(void);

	ClapTrap		&operator=(const ClapTrap &rhs);

	virtual void	attack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string	&getName(void) const;
};

std::ostream	&operator<<(std::ostream &ostream, const ClapTrap &myClass);

#endif