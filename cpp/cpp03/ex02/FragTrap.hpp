/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:55:38 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 14:58:39 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap(void);
    ~FragTrap(void);
	
    FragTrap &operator=(const FragTrap &);
    void highFivesGuys(void);

};

#endif // FRAGTRAP_HPP
