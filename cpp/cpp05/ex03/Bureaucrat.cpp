#include "Bureaucrat.hpp"

#include "AForm.hpp"

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

// Helper function to validate grades and throw excceptions for Invalid grades
std::exception* Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
         throw GradeTooLowException();
    }
    return NULL;  // Grade is valid
}


// Constructors
Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{	
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	validateGrade(grade);
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
		validateGrade(grade);
		this->setGrade(grade);

}

// Deconstructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();

	return *this;
}

// Public Methods
void	Bureaucrat::incrementGrade(void)
{
		validateGrade(this->_grade - 1);
		this->setGrade(this->_grade - 1);


}

void	Bureaucrat::decrementGrade(void)
{

		validateGrade(this->_grade + 1);
		this->setGrade(this->_grade + 1);


}


void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}


void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error execute form:"<<  e.what() << '\n';
	}	
}


// Getter
const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}
int	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}
// Setter
void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}


std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}
