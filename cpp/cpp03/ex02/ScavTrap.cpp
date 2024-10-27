/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:16:29 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 14:54:07 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// OCF ///////
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " DIFFERENT constructor called" << std::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap " << _name << " constructor by copy called" << std::endl;
}

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap no name: constructor void called" << std::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}
// ------------ Helper function ---------------//
bool check_health_and_energy_scav(unsigned int _health,unsigned int _energyPoint,std::string action,std::string  _name)
{
	if (_health==0)
	{
		std::cout << "ScavTrap " << _name
                  << ": could not " << action << "- ITS DEAD" << std::endl;
		return 1;
	}
	if (_energyPoint==0)
	{
		std::cout << "ScavTrap " << _name
                  << ": could not " << action << " - OUT OF ENERGY" << std::endl;
		return 1;
	}
	return 0;
}

// --- Attack   ------------------//

void ScavTrap::attack(const std::string &target) {

	if (check_health_and_energy_scav(_health,_energyPoint,"attack",_name) !=1)
	{
        std::cout << "ScavTrap " << _name << " ATTACKS " << target
                  << " FURIOSLY, causing " << _attackDamage << " points of damage to the enemy!"
                  << std::endl;
        _energyPoint--;

	}

}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
              << std::endl;
}

