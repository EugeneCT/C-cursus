/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:51 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:37:07 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &src);
  ~Dog();
  Dog &operator=(Dog const &src);

private:
  void makeSound(void) const;
  Brain *_brain;

};