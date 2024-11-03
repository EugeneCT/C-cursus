/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:49:04 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:38:04 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
  if (this != &src)
    *this = src;
std::cout << "Brain copy Constructor called" << std::endl;
}


Brain::~Brain(void) {
std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &src) {
    if (this == &src)
		return *this;
	for (size_t i = 0; i < 100; ++i) {
		this->ideas[i] = src.ideas[i];
	}
    return *this;
}
