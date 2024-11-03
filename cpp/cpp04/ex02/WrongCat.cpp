/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:20:21 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:44:44 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat") {
  if (this != &src)
    *this = src;
std::cout << "WrongCat Default Constructor called" << std::endl;

}

WrongCat::~WrongCat(void) {
std::cout << "WrongCat  Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "What does the WrongCat says? Quack Quack!!" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
std::cout << "WrongCat assignment operator called" << std::endl;

  if (this != &src)
    this->_type = src.getType();
  return (*this);
}