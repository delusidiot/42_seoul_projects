#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap(void);

	DiamondTrap	&operator=(const DiamondTrap &other);

	virtual void	attack(const std::string &target);
	void			whoAmI(void) const;
};

#endif
