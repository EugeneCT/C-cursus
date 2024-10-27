/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:32:20 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 14:41:08 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	
	
    ClapTrap ash("Ash");
	ScavTrap lilo("Lilo");

	lilo.guardGate();
	
    ash.setAttackDamage(7);
	ash.attack("Lilo");
	lilo.takeDamage(ash.getAttackDamage());
	std::cout << "ScavTrap Lilo have " << lilo.getHealth()<< "hp left" 
				<< std::endl;

	
	lilo.attack("Ash");
	ash.takeDamage(lilo.getAttackDamage());
	std::cout << "ClapTrap Ash have " << ash.getHealth()<< "hp left" 
				<< std::endl;
	lilo.setAttackDamage(140);
	lilo.setHealth(1);
	lilo.setEnergyPoint(1);
	lilo.beRepaired(200);
	std::cout << "ScavTrap Lilo have " << lilo.getHealth()<< "hp left" 
				<< std::endl;
	lilo.beRepaired(200);
	lilo.attack("Ash");

	ash.attack("Lilo");


	

	// gary.setAttackDamage(2);

	
	// std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
	// 		<< std::endl;
	

	// gary.attack("Ash");
	// ash.takeDamage(gary.getAttackDamage());

	// ash.attack("Gary");
	// gary.takeDamage(ash.getAttackDamage());
	
	
	// gary.attack("Ash");
	// gary.beRepaired(5);
	// gary.setHealth(1);
	// gary.setEnergyPoint(1);
	// gary.beRepaired(5);
	// 	std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
	// 		<< std::endl;
	// gary.beRepaired(5);
	// gary.attack("Ash");
	// ash.attack("Gary");	
	// gary.takeDamage(ash.getAttackDamage());
	// std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
	// 		<< std::endl;




    return 1;
}