#include "Bureaucrat.hpp"

int main()
{
	try{
		int x = 42;
		throw x;
	}
	catch(int x){
		std::cout << "Exception caught: " << x << std::endl;
	}
	// try {
	// 	Bureaucrat a("Alice", 1);
	// 	std::cout << a << std::endl;

	// 	a.incrementGrade(1); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }
	// std::cout << "--------------------\n" ;
	// try {
	// 	Bureaucrat b("Bob", 150);
	// 	std::cout << b << std::endl;

	// 	b.decrementGrade(1); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }
	// std::cout << "--------------------\n" ;
	// try {
	// 	Bureaucrat c("Charlie", 0); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cout << "Exception caught during Charlie creation: " << e.what() << std::endl;
	// }
	// std::cout << "--------------------\n" ;
	// try {
	// 	Bureaucrat d("Dave", 200); // Should throw
	// } catch (const std::exception &e) {
	// 	std::cout << "Exception caught during Dave creation: " << e.what() << std::endl;
	// }
	// std::cout << "--------------------\n" ;
	// try {
	// 	Bureaucrat e("Eve", 42);
	// 	std::cout << e << std::endl;

	// 	e.incrementGrade(1);
	// 	std::cout << "After increment: " << e << std::endl;

	// 	e.decrementGrade(1);
	// 	e.decrementGrade(1);
	// 	std::cout << "After two decrements: " << e << std::endl;

	// } catch (const std::exception &e) {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }
	// std::cout << "--------------------\n" ;
	return 0;
}
