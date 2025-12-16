
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern unpaidIntern;
	Bureaucrat boss("Boss", 150);
	AForm* form1 = unpaidIntern.makeForm("shrubbery creation", "Home");

	try {
		if (form1) {
			std::cout << *form1 << std::endl;
			boss.signAForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}

		AForm* form2 = unpaidIntern.makeForm("robotomy request", "Bender");
		if (form2) {
			std::cout << *form2 << std::endl;
			boss.signAForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}

		AForm* form3 = unpaidIntern.makeForm("presidential pardon", "Alice");
		if (form3) {
			std::cout << *form3 << std::endl;
			boss.signAForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}

		AForm* form4 = unpaidIntern.makeForm("unknown form", "Target");
		if (form4) {
			delete form4;
		}
	}
	catch (const std::exception& e) {
		std::cout << "EXCEPTION in main: " << e.what() << std::endl;
	}
	return 0;
}
