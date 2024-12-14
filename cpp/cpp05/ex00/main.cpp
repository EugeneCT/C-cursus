#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat b("Ali",199);  // Create a Bureaucrat with grade 100
	b.decrementGrade();
	std::cout << "Bureaucrat name: " << b.getName() << ", grade: " << b.getGrade() << std::endl;
	b.incrementGrade();
    std::cout << "Bureaucrat name: " << b.getName() << ", grade: " << b.getGrade() << std::endl;

	// Bureaucrat c("Ali",1);  // Create a Bureaucrat with grade 100
    // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
	// c.incrementGrade();
    // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;

	// Bureaucrat c("Ali",149);  // Create a Bureaucrat with grade 100
    // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
	// c.decrementGrade();
    // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
	// c.decrementGrade();
    // std::cout << "Bureaucrat name: " << c.getName() << ", grade: " << c.getGrade() << std::endl;
}
