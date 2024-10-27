/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:09:26 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 14:28:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class ClapTrap {
  public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap(void);
    ~ClapTrap(void);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setName(const std::string &value);
    void setHealth(const unsigned int &value);
    void setEnergyPoint(const unsigned int &value);
    void setAttackDamage(const unsigned int &value);

    std::string  getName(void) const;
    unsigned int getHealth(void) const;
    unsigned int getEnergyPoint(void) const;
    unsigned int getAttackDamage(void) const;

    ClapTrap &operator=(const ClapTrap &);

  // Change to protected so that derived class can access also
  protected:
    std::string  _name;
	unsigned int _health;
    unsigned int _energyPoint;
	unsigned int _attackDamage;
	
};
#endif