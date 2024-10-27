/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:58:39 by cliew             #+#    #+#             */
/*   Updated: 2024/10/26 10:01:02 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_numFrac=8;
	public:
	// Constructors and Deconstructors
		Fixed();

		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &copy);
		~Fixed();

	// Overloaded Operators
		Fixed &operator=(const Fixed &src);

		// Comparison Operators
		// Const at the end means its a constant member function, it would not alter any variable value in it
		bool operator>(const Fixed &copy)const;
		bool operator<(const Fixed &copy)const;
		bool operator>=(const Fixed &copy)const;
		bool operator<=(const Fixed &copy)const;
		bool operator==(const Fixed &copy)const;
		bool operator!=(const Fixed &copy)const;

		// Arithmetic Operators
		Fixed operator+(const Fixed &copy)const;
		Fixed operator-(const Fixed &copy)const;
		Fixed operator*(const Fixed &copy)const;
		Fixed operator/(const Fixed &copy)const;

		// pre-increment Operators
		Fixed& operator++();
		Fixed& operator--();
		// post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

	// Public Methods

//
// A static function in C++ is a member function of a class that is associated with the class itself rather than any particular instance of the class.

//Class-Level Access:
// Static functions can be called on the class itself, not requiring an instance of the class.

// No Access to this:
// Static functions do not have access to the this pointer. This means they cannot access non-static member variables or non-static member functions directly.

// Shared Among Instances:
//Static functions are shared among all instances of the class. There is only one copy of the static function, regardless of how many objects of the class are created.


		float toFloat(void)const;
		int toInt(void)const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first,  const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);

	// Getter
		int getRawBits(void)const;
	// Setter
		void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif