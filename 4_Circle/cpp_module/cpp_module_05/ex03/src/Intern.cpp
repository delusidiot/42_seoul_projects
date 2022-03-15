#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	t_formList forms[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	Form	*resultForm = NULL;

	for (int i = 0; forms[i].formType != NULL; i++)
	{
		if (forms[i].formName == formName)
			resultForm = forms[i].formType;
		else
			delete forms[i].formType;
	}
	if (resultForm == NULL)
		std::cout << "Intern did not find the form " << formName << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return resultForm;
}

std::ostream &operator<<(std::ostream &ostr, Intern const &instance)
{
	(void)instance;
	ostr << "Intern" << std::endl;
	return ostr;
}