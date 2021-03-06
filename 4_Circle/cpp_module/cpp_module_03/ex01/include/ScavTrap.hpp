#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &src);
	virtual ~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &other);

	virtual void	attack(const std::string &target) const;
	void			guardGate(void);
};

#endif