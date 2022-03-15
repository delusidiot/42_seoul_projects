#ifndef FORM_HPP_
# define FORM_HPP_

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	Form(void);
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	static const int	lowestGrade;
	static const int	highestGrade;
public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &src);
	~Form(void);

	Form	&operator=(const Form &rhs);
	const std::string	&getName(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;
	bool				isSigned(void) const;

	void	checkGrades(void) const;
	void	checkExecutability(const Bureaucrat &bureaucrat) const;
	bool	beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class CantExecuteForm : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &ostr, const Form &instance );

#endif
