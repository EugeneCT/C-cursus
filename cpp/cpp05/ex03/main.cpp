
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
    srand(time(0)); // Randomized seed by currnt time

	Intern Jr_Intern;
	AForm *robo_intern;

	robo_intern = Jr_Intern.makeForm("DoYouKnowMe", "Hmmmm");
	delete robo_intern;

	robo_intern = Jr_Intern.makeForm("PresidentialPardonForm", "Lala");

	std::cout << robo_intern->getName() << std::endl;
	
	Bureaucrat Mr_Shrubby("Mr_Shrubby", 1);
	Mr_Shrubby.signForm(*robo_intern);

  	Mr_Shrubby.executeForm(*robo_intern);
	delete robo_intern;
	return (0);

}