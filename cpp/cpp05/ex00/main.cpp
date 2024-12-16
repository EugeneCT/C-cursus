#include "Bureaucrat.hpp"

int main(void)
{	

	try{
		Bureaucrat b("Alien",1);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const std::exception& e) 
	{
        std::cerr << "Error: " << e.what() << std::endl;

	}


}
