#ifndef ICE_HPP_
# define ICE_HPP_

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &src);
	~Ice(void);

	Ice		&operator=(const Ice &rhs);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter& target);
};

#endif
