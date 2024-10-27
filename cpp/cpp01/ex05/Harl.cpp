/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:27:08 by cliew             #+#    #+#             */
/*   Updated: 2024/09/22 21:36:08 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug(void) 
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void	Harl::info(void) 
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

void	Harl::warning(void) 
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void	Harl::error(void) 
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}


void Harl::complain(std::string level) {
	
    complainFunction complaints[4] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };
        std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        
        for (size_t i = 0; i < 4; ++i) {
            if (level == levels[i]) {
                (this->*complaints[i])(); // Call the appropriate function
                return;
            }
        }
        
        std::cout << "Unknown level :" << level << std::endl;
    }

