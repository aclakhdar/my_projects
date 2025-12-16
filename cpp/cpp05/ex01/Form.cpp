#include "Form.hpp"

Form::Form(void) : name("default"), grade_to_execute(150), grade_to_sign(150)
{
	std::cout << "Default constructor called" << std::endl;
	this->_signed = false;
	return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_execute(grade_to_execute), grade_to_sign(grade_to_sign)
{
	std::cout << "argumant constructor called" << std::endl;
	this->_signed = false;
	check_grade(grade_to_execute);
	check_grade(grade_to_sign);
	return ;
}

Form::Form(const Form &other) : name(other.name), grade_to_execute(other.grade_to_execute), grade_to_sign(other.grade_to_sign)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_signed = other._signed;
	return ;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

void Form::check_grade(int grade) //call after signing the grade!!!
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::string Form::get_name()const
{
	return this->name;
}

bool	Form::is_sign()const
{
	if (this->_signed)
		return true;
	return false;
}

int	Form::get_execute_grade()const
{
	return this->grade_to_execute;
}

int	Form::get_sign_grade()const
{
	return this->grade_to_sign;
}

void Form::beSigned(Bureaucrat const& a)
{
	if (a.getGrade() <= this->grade_to_sign)
	{
		this->_signed = true;
		std::cout << "bureaucrat " << a.getName() << " signed the form : " << this->get_name() << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.get_name() << ", form grade to sign " << form.get_sign_grade()
	<< ", form grade to execute " << form.get_execute_grade()
	<< ", is signed: " << (form.is_sign() ? "yes" : "no");
	return os;
}
