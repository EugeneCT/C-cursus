/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:49:02 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:37:39 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
public:
	Brain(const std::string &type); // Constructor
	Brain(void);                   // Default constructor

	Brain(const Brain &src);      // Copy constructor
	Brain &operator=(Brain const &src);   // Copy assignment

	virtual ~Brain(void);          // Desctructor


// virtual means it could be overridden by derived class


protected:
  std::string ideas[100];
};

