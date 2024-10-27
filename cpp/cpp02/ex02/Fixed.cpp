/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:58:34 by cliew             #+#    #+#             */
/*   Updated: 2024/10/26 10:04:31 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed(void): _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _value(value << this->_numFrac)
{  
	//std::cout << "Int constructor called" << std::endl;
} 

Fixed::Fixed(const float value): _value(roundf(value * (1<<this->_numFrac) ))
{  
	//std::cout << "Float constructor called" << std::endl;
} 

Fixed::Fixed(Fixed const &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << this->_numFrac);
}

int	Fixed::toInt(void) const {
	return (int)(this->_value >> this->_numFrac);
}



int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}


//--------------------- Arimethic ---------------------//
Fixed	Fixed::operator+(const Fixed  &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

// --------------------- Boolean ---------------------//

bool	Fixed::operator==(const Fixed &copy) const
{
	 return this->getRawBits() == copy.getRawBits();
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return this->getRawBits() != copy.getRawBits();

}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

// -------------Increment / Decrement --------------------//


// The prefix increment operator (++obj) modifies the object and returns a reference to it.
// The postfix increment operator (obj++) modifies the object but returns the original value before the increment.
// Post fix Returns a copy of the original object before it was incremented. This means that obj is modified, but you get the old value.
Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int value)
{
	Fixed	aux(*this);

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + 1);
	return (aux);
}

Fixed	Fixed::operator--(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - 1);
	return (aux);
}

// ----------------- min/max ----


Fixed& Fixed::min( Fixed &first, Fixed &second ) {
    if ( first.getRawBits() < second.getRawBits() )
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed &first,const Fixed &second ) {
    if ( first.getRawBits() < second.getRawBits() )
        return first;
    return second;
}


Fixed& Fixed::max( Fixed &first, Fixed &second ) {
    if ( first.getRawBits() > second.getRawBits() )
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed &first,const Fixed &second ) {
    if ( first.getRawBits() > second.getRawBits() )
        return first;
    return second;
}



