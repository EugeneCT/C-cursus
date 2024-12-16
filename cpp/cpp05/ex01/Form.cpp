#include "Form.hpp"
#include "Bureaucrat.hpp"
// Constructors
Form::Form(void): _name("default"), _is_signed(false), _sign_grade(70), _exec_grade(1)
{
	std::cout << "Form Default Constructor called" << std::endl;
}


Form::Form(const std::string& name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form Constructor called for " << this->getName() <<
    " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
    std::endl;


	if (_sign_grade > 150 || _exec_grade > 150) {
		throw GradeTooLowException();  // Exceeds max allowed grade
	}

	if (_sign_grade < 1 || _exec_grade < 1) {
		throw GradeTooHighException();  // Below minimum allowed grade
	}
  

}



Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

// Form::Form(int sign_grade, int exec_grade)
//     : _name("default"),
//       _is_signed(false),
//       _sign_grade((sign_grade >= 1 && sign_grade <= 150) ? sign_grade : 70),  // Default to 70 if invalid
//       _exec_grade((exec_grade >= 1 && exec_grade <= 150) ? exec_grade : 140)  // Default to 140 if invalid
// {
//     std::cout << "Form Constructor called for " << this->getName() <<
//     " with sign-grade of " << _sign_grade << " and execution-grade of " << _exec_grade << std::endl;

//     // Validation can be done, but the grades have already been set correctly
//     try {
//         Bureaucrat::validateGrade(this->getSignGrade());
//     } catch (const std::exception& e) {
//         std::cerr << "Error - Sign Grade: " << e.what() << ", already defaulted to " << _sign_grade << std::endl;
//     }

//     try {
//         Bureaucrat::validateGrade(this->getExecGrade());
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << ", already defaulted to " << _exec_grade << std::endl;
//     }
// }

// Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
// {
// 	std::cout << "Form Constructor called for " << this->getName() <<
// 	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
// 	std::endl;

// 	const int i = this->getSignGrade();
// 	const int j = this->getExecGrade();

	// try{
	// 	Bureaucrat::validateGrade(this->getSignGrade());
	// }
	// catch (const std::exception& e) {
    //     std::cerr << "Error - Sign Grade: " << e.what() << ", defaulting to 70" << std::endl;
	// 	this-_sign_grade=70;
    // }

	// try{
	// 	Bureaucrat::validateGrade(this->getExecGrade());

	// }
	// catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << ", defaulting to 75" << std::endl;
	// 	this->_exec_grade=140;

    // }

// 	if (i > 150 || j > 150)
// 		throw(Form::GradeTooLowException());
// 	else if( i < 1 || j < 1)
// 		throw(Form::GradeTooHighException());
// }

// Form::Form(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
// {
// 	std::cout << "Form Constructor called for " << this->getName() <<
// 	" with sign-grade of " << this->getSignGrade() <<
// 	" and execution-grade of " << this->getExecGrade() << std::endl;
// }







// Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
// {
// 	std::cout << "Form Constructor called for " << this->getName() <<
// 	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
// 	std::endl;
// 	const int i = this->getSignGrade();
// 	const int j = this->getExecGrade();
// 	if (i > 150 || j > 150)
// 		throw(Form::GradeTooLowException());
// 	else if( i < 1 || j < 1)
// 		throw(Form::GradeTooHighException());
// }

// Deconstructors
Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	//nothing to assign in this class
	return *this;
}

// Public Methods
void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
		else if (!this->getIsSigned())  	{
		this->_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

// Getter
const std::string	Form::getName(void)const
{
	return (this->_name);
}


bool	Form::getIsSigned(void)const
{
	return (this->_is_signed);
}

int	Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

// Setter

// Exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

// ostream Overload
std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecGrade() << std::endl;
	return (os);
}