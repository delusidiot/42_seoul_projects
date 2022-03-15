#ifndef CURE_HPP_
# define CURE_HPP_

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &src);
	~Cure(void);

	Cure	&operator=(const Cure &rhs);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter& target);
};

#endif
