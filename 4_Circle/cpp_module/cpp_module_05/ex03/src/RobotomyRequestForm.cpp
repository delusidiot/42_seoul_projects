#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: Form("RobotomyRequestForm", 72, 45), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
: Form(src), _target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "Can't copy anything" << std::endl;
	rhs.getTarget();
	return *this;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << "* Unbearable drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << "The victi... " << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "The robotomization on " << this->_target << " may or may not have been a complete and utter failure." << std::endl;
}

/* std::ostream &	operator<<( std::ostream & ostr, RobotomyRequestForm const & instance)
{
 	ostr << "The value of RobotomyRequestForm is..." << std::endl;
 	return ostr;
} */