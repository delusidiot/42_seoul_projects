#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: Form("PresidentialPardonForm", 25, 5), _target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
: Form(src), _target(src.getTarget())
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "Can't copy anything" << std::endl;
	rhs.getTarget();
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

/* std::ostream &	operator<<( std::ostream & ostr, PresidentialPardonForm const & instance)
{
 	ostr << "The value of PresidentialPardonForm is..." << std::endl;
 	return ostr;
} */
