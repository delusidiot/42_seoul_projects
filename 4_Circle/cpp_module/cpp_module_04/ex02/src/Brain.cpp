#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor for Brain called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Copy constructor for Brain called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Destructor for Brain called" << std::endl;
}

Brain &	Brain::operator=(const Brain &rhs)
{
	std::cout << "Assignement operator for Brain called" << std::endl;
	for (int i = 0; i < Brain::numberOfIdeas; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}