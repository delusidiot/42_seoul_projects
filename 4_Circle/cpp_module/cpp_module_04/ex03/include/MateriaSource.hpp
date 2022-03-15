#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
	const static int	_materias_size = 4;
	AMateria		*_materias[MateriaSource::_materias_size];
	int			_number_learned;
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &src);
	~MateriaSource(void);

	MateriaSource	&operator=(const MateriaSource &rhs);

	virtual void		learnMateria(AMateria *materia_to_learn);
	virtual AMateria	*createMateria(std::string const & type);

	void			printMaterias(void) const ;
};

#endif
