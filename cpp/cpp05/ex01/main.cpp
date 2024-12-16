#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{



	Form id_form("Form 1", 100, 90);
	Bureaucrat mr_slow;
	Bureaucrat mr_id("Mr President", 100);
	std::cout << id_form;
	
	mr_slow.signForm(id_form);
	std::cout << id_form;

	mr_id.signForm(id_form);
	std::cout << id_form;



	return (0);
}