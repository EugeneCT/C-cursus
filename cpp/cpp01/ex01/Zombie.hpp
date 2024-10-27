#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie();
		void	announce(void) const;
		void	setName(std::string);
};

Zombie	*zombieHorde(int N, std::string name);


#endif