#ifndef INTERN_HPP_
# define INTERN_HPP_

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	typedef struct	s_formList
	{
		std::string	formName;
		Form		*formType;
	}				t_formList;
public:
	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator=(const Intern &rhs);

	Form	*makeForm(const std::string &formName, const std::string &target) const;
};

std::ostream	&operator<<( std::ostream &ostr, const Intern &instance );

#endif
