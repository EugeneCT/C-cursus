/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:55:33 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 14:57:56 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>


// -------------- OCF --------//
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    _health = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << _name << " constructor by copy called"
              << std::endl;
}

FragTrap::FragTrap(void) {
    std::cout << "FragTrap no name: constructor void called" << std::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << ": high fives request" << std::endl;
}

