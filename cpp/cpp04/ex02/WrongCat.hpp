/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:20:24 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:44:21 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &src);
  ~WrongCat();
  WrongCat &operator=(WrongCat const &src);

private:
  void makeSound(void) const;
};