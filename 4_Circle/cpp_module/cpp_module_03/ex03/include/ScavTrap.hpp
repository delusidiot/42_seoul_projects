#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &src);
	virtual ~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &other);

	virtual void	attack(const std::string &target);
	void			guardGate(void);
};

#endif