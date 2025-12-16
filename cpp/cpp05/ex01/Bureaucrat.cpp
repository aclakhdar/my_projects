#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default")
{
	std::cout << "Default constructor called" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "argumant constructor called" << std::endl;
	//check here
	set_grade(grade);
}

Bureaucrat::Bureaucrat(std::string name) : name(name)
{
	std::cout << "argumant constructor called" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	std::cout << "argumant constructor called" << std::endl;
	//check here
	set_grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	std::cout << "Copy constructor called" << std::endl;
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Bureaucrat::set_grade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

void Bureaucrat::incrementGrade(int amount)
{
	set_grade(this->grade - amount);
}

void Bureaucrat::decrementGrade(int amount)
{
	set_grade(this->grade + amount);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void	Bureaucrat::signForm(Form& a)
{
	if(a.is_sign())
	{
		std::cout<< "the form is already signed \n";
		return ;
	}

	try
	{
		a.beSigned(*this);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << "the form : " << "\"" + a.get_name() + "\" " << " signed failed : " << e.what() << '\n';
	}

}
