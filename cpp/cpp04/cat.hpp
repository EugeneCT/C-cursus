/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:20:24 by cliew             #+#    #+#             */
/*   Updated: 2024/10/27 16:24:05 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();
  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;
};