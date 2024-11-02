/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:16:06 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 16:20:13 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>

class Animal {
public:
  Animal(const std::string &type);
  Animal(const Animal &src);
  Animal(void);
  virtual ~Animal(void);
  Animal &operator=(Animal const &src);

  const std::string &getType(void) const;

// virtual means it could be overridden by derived class
  virtual void makeSound(void) const;


protected:
  std::string _type;
};