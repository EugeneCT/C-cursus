#include "ClapTrap.hpp"

int main( void )
{
	
	
    ClapTrap ash("Ash");
    ClapTrap gary("Gary");

	
    ash.setAttackDamage(7);
	gary.setAttackDamage(2);

	ash.attack("Gary");
	gary.takeDamage(ash.getAttackDamage());
	
	std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
			<< std::endl;
	

	gary.attack("Ash");
	ash.takeDamage(gary.getAttackDamage());

	ash.attack("Gary");
	gary.takeDamage(ash.getAttackDamage());
	
	std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
			<< std::endl;

	gary.attack("Ash");
	gary.beRepaired(5);
	gary.setHealth(1);
	gary.setEnergyPoint(1);
	gary.beRepaired(5);
		std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
			<< std::endl;
	gary.beRepaired(5);
	gary.attack("Ash");
	ash.attack("Gary");	
	gary.takeDamage(ash.getAttackDamage());
	std::cout << "ClapTrap Gary have " << gary.getHealth()<< "hp left" 
			<< std::endl;




    return 1;
}