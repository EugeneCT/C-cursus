/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:16:06 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:46:04 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal(const std::string &type); // Constructor
	WrongAnimal(void);                   // Default constructor

	WrongAnimal(const WrongAnimal &src);      // Copy constructor
	WrongAnimal &operator=(WrongAnimal const &src);   // Copy assignment

	virtual ~WrongAnimal(void);          // Desctructor


// virtual means it could be overridden by derived class
  	virtual void makeSound(void) const;
 	const std::string &getType(void) const;


protected:
  std::string _type;
};

