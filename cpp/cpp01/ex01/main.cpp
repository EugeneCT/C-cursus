#include "Zombie.hpp"

int	main(void)
{
	Zombie		*horde;
	int			 Zombies_count = 3;
	std::string	name = "Mickey";


	horde = zombieHorde(Zombies_count, name);

	for (int i = 0; i < Zombies_count; i++)
		horde[i].announce();
	
	delete [] horde;
	std::cout << Zombies_count << " zombies named " << name <<" is dead." << std::endl;
	return (0);
}