#include "AForm.hpp"

AForm::AForm(void) : name("default"), grade_to_execute(150), grade_to_sign(150)
{
	std::cout << "Default constructor called" << std::endl;
	this->_signed = false;
	return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_execute(grade_to_execute), grade_to_sign(grade_to_sign)
{
	std::cout << "argumant constructor called" << std::endl;
	this->_signed = false;
	check_grade(grade_to_execute);
	check_grade(grade_to_sign);
	return ;
}

AForm::AForm(const AForm &other) : name(other.name), grade_to_execute(other.grade_to_execute), grade_to_sign(other.grade_to_sign)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_signed = other._signed;
	return ;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

void AForm::check_grade(int grade) //call after signing the grade!!!
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::string AForm::get_name()const
{
	return this->name;
}

bool	AForm::is_sign()const
{
	if (this->_signed)
		return true;
	return false;
}

int	AForm::get_execute_grade()const
{
	return this->grade_to_execute;
}

int	AForm::get_sign_grade()const
{
	return this->grade_to_sign;
}

void AForm::beSigned(Bureaucrat const& a)
{
	if (a.getGrade() <= this->grade_to_sign)
	{
		this->_signed = true;
		std::cout << "bureaucrat " << a.getName() << " signed the AForm : " << this->get_name() << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.get_name() << ", AForm grade to sign " << AForm.get_sign_grade()
	<< ", AForm grade to execute " << AForm.get_execute_grade()
	<< ", is signed: " << (AForm.is_sign() ? "yes" : "no");
	return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->is_sign())
		throw FormNotSignedException();
	if (executor.getGrade() > this->get_execute_grade())
		throw GradeTooLowException();
	this->executeForm();
}
