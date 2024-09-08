/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:46:53 by cliew             #+#    #+#             */
/*   Updated: 2024/09/08 23:45:20 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


int	main() {
	PhoneBook	PhoneBook;

	str			line;

	system("clear");
	std::cout << "Hello ! This is a phonebook." << std::endl;
	while (1)
	{
		std::cout << "Key in 1 of these commands : ADD, SEARCH or EXIT\n";
		std::getline(std::cin, line);
		if (!line.compare("ADD"))
			PhoneBook.add_contact();
		else if (!line.compare("SEARCH"))
			PhoneBook.search_contact();
		else if (!line.compare("EXIT"))
		{
			std::cout << "See you!" << std::endl;
			break;
		}
	}
	sleep(1);
	return 0;
}