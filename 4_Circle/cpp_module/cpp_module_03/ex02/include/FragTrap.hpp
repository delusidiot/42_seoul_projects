#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &src);
	virtual ~FragTrap(void);

	FragTrap	&operator=(const FragTrap &other);

	void		highFivesGuys(void);
};

#endif
