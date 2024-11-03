/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:16:37 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 12:50:01 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(const std::string &type) : _type(type){
	std::cout << "Animal Constructor called , for type " << type << std::endl;
}
Animal::Animal(void) : _type("Animal") {
std::cout << "Animal Constructor called, for type " << _type  << std::endl;
}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
std::cout << "Animal copy Constructor called" << std::endl;
}

Animal::~Animal(void) {
std::cout << "Animal Destructor called" << std::endl;
}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "Default animal sound" << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
	std::cout << "Animal assignment operator called" << std::endl;

  if (this != &src)
    this->_type = src.getType();
  return (*this);
}