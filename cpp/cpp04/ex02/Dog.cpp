/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:46 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:34:26 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog Constructor called" << std::endl;
	_brain = new Brain;

}

Dog::Dog(const Dog &src) : Animal("Dog") {
  if (this != &src)
    *this = src;
  _brain = new Brain;

std::cout << "Dog Copy Constructor called" << std::endl;

}

Dog::~Dog(void) {
 delete _brain;

std::cout << "Dog  Destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "What does the Dog says? Woof Woof!" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
std::cout << "Dog assignment operator called" << std::endl;

  if (this != &src)
    this->_type = src.getType();
  this->_brain->operator=(*src._brain);

  return (*this);
}

