#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
: _number_learned(0)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia_to_learn)
{
	if (materia_to_learn == NULL)
		std::cout << "Can't learn NULL!" << std::endl;
	else if (this->_number_learned >= MateriaSource::_materias_size)
		std::cout << "Can't learn any more materias" << std::endl;
	else
	{
		this->_materias[this->_number_learned] = materia_to_learn;
		this->_number_learned++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MateriaSource::_materias_size && this->_materias[i]; i++)
	{
		if (type == this->_materias[i]->getType())
			return this->_materias[i]->clone();
	}
	return NULL;
}

void MateriaSource::printMaterias(void) const
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			std::cout << i << ": " << this->_materias[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}