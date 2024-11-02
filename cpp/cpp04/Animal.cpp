/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:16:37 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 16:26:12 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(const std::string &type) : _type(type){
	std::cout << "Animal Constructor called" << std::endl
}
Animal::Animal(void) : _type("Animal") {
std::cout << "Cat Constructor called" << std::endl
}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
std::cout << "Cat Constructor called" << std::endl}

Animal::~Animal(void) {
	LOG("destructor Animal empty")
}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}