#include "Bureaucrat.hpp"

const int Bureaucrat::lowestGrade = 150;
const int Bureaucrat::highestGrade = 1;

Bureaucrat::Bureaucrat(void)
: _name("Anonymous"), _grade(Bureaucrat::lowestGrade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name), _grade(grade)
{
	checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	std::cout << "Name is const and can't be overwritten, only grade was copied" << std::endl;
	return *this;
}

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(int quantity)
{
	this->_grade -= quantity;
	checkGrade();
}

void Bureaucrat::decrementGrade(int quantity)
{
	this->_grade += quantity;
	checkGrade();
}

bool Bureaucrat::signForm(Form &form) const
{
	if (form.beSigned(*this))
	{
		std::cout << this->_name << " signs form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->_name << " cannot sign form " << form.getName() << " because their grade is not high enough" << std::endl;
		return false;
	}
}

bool Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.checkExecutability(*this);
		std::cout << this->_name << " executes form " << form.getName() << std::endl;
		return true;
	}
	catch (Form::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}

void	Bureaucrat::checkGrade(void) const
{
	if (this->_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream & os, Bureaucrat const & instance)
{
	os << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade you set is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade you set is too low";
}