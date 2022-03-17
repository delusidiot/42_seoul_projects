#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(void);
	AMateria(const std::string &type);
	AMateria(AMateria const &src);
	virtual	~AMateria();

	AMateria	&operator=(const AMateria &rhs);

	const std::string	&getType(void) const;
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter& target) = 0;
};

#endif