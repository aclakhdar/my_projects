#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
#include "Bureaucrat.hpp"

#define SIGN 0
#define EXECUTE 1

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				_signed;
		const int			grade_to_execute;
		const int			grade_to_sign;
	public:
		Form(void);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& other);
		Form &operator=(const Form &other);
		~Form();
		void check_grade(int grade);
		std::string get_name() const;
		bool		is_sign()const;
		int			get_sign_grade()const;
		int			get_execute_grade()const;
		void		beSigned(Bureaucrat const& a);
		class GradeTooHighException : public std::exception
		{
			public:
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif

