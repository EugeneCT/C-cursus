#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie")
{
	return ;
}

Zombie::Zombie(std::string _name) : name(_name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string _name)
{
	name = _name;
}