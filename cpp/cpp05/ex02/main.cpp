
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


// int main(void)
// {

// 	// Bureaucrat b("Ali",199);  // Create a Bureaucrat with grade 100
// 	// b.decrementGrade();
// 	// std::cout << "Bureaucrat name: " << b.getName() << ", grade: " << b.getGrade() << std::endl;
// 	// b.incrementGrade();
//     // std::cout << "Bureaucrat name: " << b.getName() << ", grade: " << b.getGrade() << std::endl;

// 	// Bureaucrat c("Ali",1);  // Create a Bureaucrat with grade 100
//     // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
// 	// c.incrementGrade();
//     // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;

// 	// Bureaucrat c("Ali",149);  // Create a Bureaucrat with grade 100
//     // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
// 	// c.decrementGrade();
//     // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
// 	// c.decrementGrade();
//     // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;

// 	Form d("Blue",110,200);

//     std::cout << "Form " << d.getName() << "grade : " <<  d.getSignGrade() << std::endl;


// }

int main(void)
{
    srand(time(0));


	// std::cout << "\033[33m" << std::endl << "Test ex01" << "\033[0m" << std::endl;
	// AForm id_form("Form 1", 100, 90);
	// Bureaucrat mr_slow;
	// Bureaucrat mr_id("Mr President", 100);
	// std::cout << id_form;
	
	// mr_slow.signForm(id_form);
	// std::cout << id_form;

	// mr_id.signForm(id_form);
	// std::cout << id_form;
	
	// return (0);


	// std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;
	// std::cout << "\033[33m" << std::endl << "Test ex02 ShrubberyCreationForm" << "\033[0m" << std::endl;
	// Bureaucrat Mr_Shrubby("Mr_Shrubby", 137);
	// ShrubberyCreationForm Shrubby_form("Hello");
	// std::cout << std::endl;
	// std::cout << Shrubby_form;
	// Mr_Shrubby.signForm(Shrubby_form);
	// std::cout << Shrubby_form;
	// Mr_Shrubby.executeForm(Shrubby_form);



	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	// Mr_Robo.executeForm(Robo_form);
	// Mr_Robo.signForm(Robo_form);
	// Mr_Robo.executeForm(Robo_form);
	// Mr_Robo.executeForm(Robo_form);
	// Mr_Robo.executeForm(Robo_form);

	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_Robo.executeForm(President_form);
	Mr_Robo.signForm(President_form);

	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);

}