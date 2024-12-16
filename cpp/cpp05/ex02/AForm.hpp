// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// classes

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;		
		virtual void	performAction() const = 0;


	public:
	// Constructors
		
		AForm(void);
  		AForm(const std::string& name = "default", int sign_grade = 70, int exec_grade = 150);

		AForm(const AForm &src);
		// Form(int sign_grade, int exec_grade);
		// Form(const std::string name);
		// Form(const std::string name, int sign_grade, int exec_grade);

	// Deconstructors
		~AForm();

	// Overloaded Operators
		AForm &operator=(const AForm &src);

	// Public Methods
		void beSigned(Bureaucrat &signer);
	// Getter
		const std::string getName(void)const;
		bool getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

		void setIsSigned(bool is_signed);
		void execute(const Bureaucrat &executor) const;

	//Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class IsNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

// ostream Overload
// std::ostream	&operator<<(std::ostream &o, Form *a);
std::ostream &operator<<(std::ostream &os,  AForm const &form);
