#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*shrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*robotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*presidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	t_form	forms[] =
	{
		{"shrubbery creation", &presidentialPardonForm},
		{"robotomy request", &robotomyRequestForm},
		{"presidential pardon", &shrubberyCreationForm}
	};
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == forms[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i].f(target));
		}
	}
	std::cout << "Error: Form '" << formName << "' not found." << std::endl;
	return NULL;
}
