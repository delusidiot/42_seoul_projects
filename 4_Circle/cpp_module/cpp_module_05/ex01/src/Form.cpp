#include "Form.hpp"

const int Form::lowestGrade = 150;
const int Form::highestGrade = 1;

Form::Form(void)
: _name(""), _isSigned(false), _gradeToSign(Form::lowestGrade), _gradeToExecute(Form::lowestGrade)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->checkGrades();
}

Form::Form(Form const &src)
: _name(src.getName()), _isSigned(src.isSigned()), _gradeToSign(src.getSignGrade()), _gradeToExecute(src.getExecuteGrade())
{
	*this = src;
}

Form::~Form(void)
{
}

Form &Form::operator=(Form const & rhs)
{
	this->_isSigned = rhs._isSigned;
	std::cout << "Name and grades are const and can't be overwritten, only isSigned was copied" << std::endl;
	return *this;
}

const std::string &Form::getName(void) const
{
	return this->_name;
}

int	Form::getSignGrade(void) const
{
	return this->_gradeToSign;
}

int	Form::getExecuteGrade(void) const
{
	return this->_gradeToExecute;
}

bool	Form::isSigned(void) const
{
	return this->_isSigned;
}

void	Form::checkExecutability(const Bureaucrat &bureaucrat) const
{
	if (this->_isSigned == false || bureaucrat.getGrade() > this->_gradeToExecute)
		throw Form::CantExecuteForm();
}

void	Form::checkGrades(void) const
{
	if (this->_gradeToExecute < Form::highestGrade || this->_gradeToSign < Form::highestGrade)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > Form::lowestGrade || this->_gradeToSign > Form::lowestGrade)
		throw Form::GradeTooLowException();
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		return true;
	}
	else
	{
		this->_isSigned = false;
		return false;
	}
}

std::ostream &operator<<(std::ostream & os, Form const & instance)
{
	os << instance.getName() << " Form has to be signed by a "
		<< instance.getSignGrade() << " grade and executed by a "
		<< instance.getExecuteGrade() << " grade, it is "
		<< ((instance.isSigned()) ? "" : "not ") << "signed";
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade you set is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade you set is too low";
}

const char *Form::CantExecuteForm::what() const throw()
{
	return "The form can't be executed";
}