#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "Default constructor called" << std::endl;
	this->target = "default";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "Default constructor called" << std::endl;
	this->target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) , target(other.target)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char * RobotomyRequestForm::rabatomyFailException::what() const throw()
{
	return ("Robotomy failed for the target.");
}

void	RobotomyRequestForm::executeForm() const
{

	std::cout << "Making some drilling noises....." << std::endl;
	int random = rand() % 2;
	if (random)
	{
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	}
	else
		throw rabatomyFailException();
}

