/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:25:44 by cliew             #+#    #+#             */
/*   Updated: 2024/09/22 21:02:50 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	private:
		void	debug(void) ;
		void	info(void) ;
		void	warning(void) ;
		void	error(void) ;

	public:
		Harl();
		~Harl();
		void	complain(std::string level) ;
};

typedef void (Harl::*complainFunction)(void) ;

#endif