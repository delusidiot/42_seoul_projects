#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
private:
	Bureaucrat(void);
	static const int	lowestGrade;
	static const int	highestGrade;
	const std::string	_name;
	int					_grade;
	void	checkGrade(void) const;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &rhs);
	const std::string	&getName(void) const;
	int					getGrade(void) const;

	void	incrementGrade(int quantity);
	void	decrementGrade(int quantity);

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
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &instance);

#endif
