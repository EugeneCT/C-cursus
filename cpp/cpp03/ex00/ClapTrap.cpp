/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:22:59 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 13:59:58 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
// Orthodox Canical Form Constructors //
ClapTrap::ClapTrap(const std::string &name)
    : _name(name),
	  _health(10),
      _energyPoint(10),
      _attackDamage(0)
       {
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap " << _name << " copy constructor called"
              << std::endl;
}

ClapTrap::ClapTrap(void) : _health(10),_energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap no name constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &value) {
	std::cout << "ClapTrap " << _name << " copy assignment constructor called";

	if (this == &value)
        return *this;
	this->_name = value._name;
	this->_health = value._health;
	this->_energyPoint = value._energyPoint;
	this->_attackDamage = value._attackDamage;
	
	return (*this);
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}


// Helper Fucntions //

bool check_health_and_energy(unsigned int _health,unsigned int _energyPoint,std::string action,std::string  _name)
{
	if (_health==0)
	{
		std::cout << "ClapTrap " << _name
                  << ": could not " << action << "- ITS DEAD" << std::endl;
		return 1;
	}
	if (_energyPoint==0)
	{
		std::cout << "ClapTrap " << _name
                  << ": could not " << action << " - OUT OF ENERGY" << std::endl;
		return 1;
	}
	return 0;
}

// Member Functions //


void ClapTrap::attack(const std::string &target) {
	if (check_health_and_energy(_health,_energyPoint,"attack",_name) !=1)
	{
			std::cout << "ClapTrap " << _name << " attacks " << target
					<< ", causing " << _attackDamage << " points of damage!"
					<< std::endl;
			
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " is attacked and takes " << amount
              << " damage! =(" << std::endl;
    if (_health > amount) {
        _health -= amount;
    } else {
        _health = 0;
        std::cout << "ClapTrap " << _name << " IS DEAD"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
  	if (check_health_and_energy(_health,_energyPoint,"repair",_name) !=1)

    {
        std::cout << "ClapTrap " << _name << " is repaired, gaining " << amount
                  << " health points!" << std::endl;
        _health += amount;
		_energyPoint--;
    }
}


// Setter
void ClapTrap::setName(const std::string &value) { _name = value; }
void ClapTrap::setHealth(const unsigned int &value) {
    _health = value;
    std::cout << "ClapTrap " << _name << " sets health to " << value
              << std::endl;
}
void ClapTrap::setEnergyPoint(const unsigned int &value) {
    _energyPoint = value;
	 std::cout << "ClapTrap " << _name << " sets energy to " << value
              << std::endl;
}

void ClapTrap::setAttackDamage(const unsigned &value) {
    std::cout << "ClapTrap " << _name << " sets attack damage to " << value
              << std::endl;
    _attackDamage = value;
}


//// Getter
std::string  ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHealth(void) const { return _health; }
unsigned int ClapTrap::getEnergyPoint(void) const { return _energyPoint; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }

