/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:55:50 by cliew             #+#    #+#             */
/*   Updated: 2024/08/01 05:39:04 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char) toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (1);
}