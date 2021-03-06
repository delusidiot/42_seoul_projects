#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &src);
	virtual ~FragTrap(void);

	FragTrap	&operator=(const FragTrap &other);

	void		highFivesGuys(void);
};

#endif
