/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:33 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:45:34 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>

class Animal {
public:
	Animal(const std::string &type); // Constructor
	Animal(void);                   // Default constructor

	Animal(const Animal &src);      // Copy constructor
	Animal &operator=(Animal const &src);   // Copy assignment

	virtual ~Animal(void);          // Desctructor


// virtual means it could be overridden by derived class
  	virtual void makeSound(void) const;
 	const std::string &getType(void) const;


protected:
  std::string _type;
};
