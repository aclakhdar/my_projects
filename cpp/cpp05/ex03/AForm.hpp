#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
#include "Bureaucrat.hpp"

#define SIGN 0
#define EXECUTE 1

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				_signed;
		const int			grade_to_execute;
		const int			grade_to_sign;
	public:
		AForm(void);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		void check_grade(int grade);
		std::string get_name() const;
		bool		is_sign()const;
		int			get_sign_grade()const;
		int			get_execute_grade()const;
		void		beSigned(Bureaucrat const& a);
		virtual void executeForm() const = 0;
		void execute(Bureaucrat const &executor) const;
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif

