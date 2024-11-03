/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:59 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:46:00 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string &type) : _type(type){
	std::cout << "WrongAnimal Constructor called , for type " << type << std::endl;
}
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
std::cout << "WrongAnimal Constructor called, for type " << _type  << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  if (this != &src)
    *this = src;
std::cout << "WrongAnimal copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
std::cout << "WrongAnimal Destructor called" << std::endl;
}

const std::string &WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "Default WrongAnimal sound" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;

  if (this != &src)
    this->_type = src.getType();
  return (*this);
}