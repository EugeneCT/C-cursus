/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:36 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:34:29 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat Constructor called" << std::endl;
	  _brain = new Brain;

}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
 _brain = new Brain;

std::cout << "Cat Copy Constructor called" << std::endl;

}

Cat::~Cat(void) {
 delete _brain;

std::cout << "Cat  Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "What does the cat says? Meow Meow!" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
std::cout << "Cat assignment operator called" << std::endl;

  if (this != &src)
    this->_type = src.getType();
  this->_brain->operator=(*src._brain);

  return (*this);
}

