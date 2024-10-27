/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:34:58 by cliew             #+#    #+#             */
/*   Updated: 2024/09/21 22:53:49 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string _type) : type(_type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string _type)
{
	type = _type;
}