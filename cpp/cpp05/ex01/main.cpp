
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 100);
        Bureaucrat charlie("Charlie", 149);

        Form taxForm("Tax Form", 150, 100);
        Form vacationRequest("Vacation Request", 100, 80);

        std::cout << taxForm << std::endl;
        std::cout << vacationRequest << std::endl;

        std::cout << "\n-- Signing Attempts --\n" << std::endl;

        alice.signForm(taxForm);
        bob.signForm(taxForm);
        bob.signForm(vacationRequest);
        charlie.signForm(vacationRequest);


        std::cout << "\n-- After Signing --\n" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << vacationRequest << std::endl;

        std::cout << "\n-- Invalid Bureaucrat Creation --\n" << std::endl;
        try {
            Bureaucrat invalidHigh("InvalidHigh", 0);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        try {
            Bureaucrat invalidLow("InvalidLow", 200);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "\n-- Invalid Form Creation --\n" << std::endl;
        try {
            Form invalidForm("Invalid Form", 0, 50);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        try {
            Form invalidForm("Invalid Form", 150, 200);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION in main: " << e.what() << std::endl;
    }

    return 0;
}
