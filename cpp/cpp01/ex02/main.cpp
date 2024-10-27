/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:21:58 by cliew             #+#    #+#             */
/*   Updated: 2024/09/21 16:54:10 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Address of the string : " << &str << std::endl;
	std::cout << "    using stringPTR " << stringPTR << std::endl;
	std::cout << "    using stringREF " << &stringREF << std::endl;
	std::cout << "Content of the string : " << str << std::endl;
	std::cout << "    using stringPTR " << *stringPTR << std::endl;
	std::cout << "    using stringREF " << stringREF << std::endl;

	return (0);
}