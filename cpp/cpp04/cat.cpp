/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:20:21 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 16:25:20 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat Constructor called" << std::endl
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
  LOG("constructor Cat copy")
}

Cat::~Cat(void) {
	LOG("destructor Cat")
}

void Cat::makeSound(void) const {
	std::cout << "MEOW MEOW i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}