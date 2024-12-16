#include "AForm.hpp"
#include "Bureaucrat.hpp"
// Constructors
AForm::AForm(void): _name("default"), _is_signed(false), _sign_grade(70), _exec_grade(1)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}


AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "AForm Constructor called for " << this->getName() <<
    " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
    std::endl;


	if (_sign_grade > 150 || _exec_grade > 150) {
		throw GradeTooLowException();  // Exceeds max allowed grade
	}

	if (_sign_grade < 1 || _exec_grade < 1) {
		throw GradeTooHighException();  // Below minimum allowed grade
	}
  

}



AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "AForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}



// Deconstructors
AForm::~AForm()
{
	std::cout << "AForm Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	//nothing to assign in this class
	return *this;
}

// Public Methods
void AForm::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());
		else if (!this->getIsSigned())  	{
		this->_is_signed = true;
		std::cout << this->getName() << " AForm was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}
void AForm::execute(const Bureaucrat &executor) const
{
	if (_is_signed == false)
		throw IsNotSignedException();
	if (_exec_grade < executor.getGrade())
		throw GradeTooLowException();

	performAction();
}

// Getter
const std::string	AForm::getName(void)const
{
	return (this->_name);
}


bool	AForm::getIsSigned(void)const
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
}

// Setter
void AForm::setIsSigned(bool is_signed)
{
	_is_signed = is_signed;
}

// Exceptions
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
const char *AForm::IsNotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

// ostream Overload
std::ostream &operator<<(std::ostream &os,  AForm const &AForm)
{
	os << "Name: " << AForm.getName() << " isSigned: " << AForm.getIsSigned() << " SignGrade: " << AForm.getSignGrade() << " ExecuteGrade: " << AForm.getExecGrade() << std::endl;
	return (os);
}