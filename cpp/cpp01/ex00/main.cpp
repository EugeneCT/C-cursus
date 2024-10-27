/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:01:19 by cliew             #+#    #+#             */
/*   Updated: 2024/09/20 23:01:21 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	alladin("Alladin");
	Zombie	mickey("Mickey");
	Zombie	zombie;

	alladin.announce();
	mickey.announce();
	zombie.announce();
	randomChump("Donald Duck");
	std::cout << std::endl;
	
	Zombie	*thor;
	thor = newZombie("Thor");
	thor->announce();
	delete(thor);

	return (0);
}