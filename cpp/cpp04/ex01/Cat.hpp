/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:45:41 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 14:37:12 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();
  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;
  Brain *_brain;

};