
// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "AForm.hpp"

// classes
class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		// Setter
		void setGrade(int grade);

	public:
	// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);

	// Deconstructors
		~Bureaucrat();

	// Overloaded Operators
		Bureaucrat &operator=(const Bureaucrat &src);

	// Public Methods
		void incrementGrade(void);
		void decrementGrade(void);
		static std::exception* validateGrade(int grade);
		void		signForm(AForm &form);
		void		executeForm(const AForm &form);


	// Getter
		const std::string getName(void)const;
		int getGrade(void)const;

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


};

// ostream Overload
std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);