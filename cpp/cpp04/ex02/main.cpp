/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:43 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 15:05:43 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"



#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

/*
    The order of constructor and destructor:
        1. Base constructor
        2. Derived constructor
        3. Derived destructor
        4.Base destructor
*/

int main( void )
{
	 const Animal* cat = new Cat();
	 std::cout << "cat Type: " << cat->getType() << " " << std::endl;
     cat->makeSound();

	//   const Animal* animal = new Animal();
	// std::cout << "animal Type: " << animal->getType() << " " << std::endl;
    //  animal->makeSound();

}

// int main( void )
// {
//     std::cout << "--------------- Animal ---------------" << std::endl;

//     const Animal* animal = new Animal();
//     // const Animal* j = new Dog();
//     const Animal* cat = new Cat();
//     const Animal* dog = new Dog();

//     std::cout << "cat Type: " << cat->getType() << " " << std::endl;
//     cat->makeSound();

// 	std::cout << "dog Type: " << dog->getType() << " " << std::endl;
//     dog->makeSound();

//  	std::cout << "animal Type: " << animal->getType() << " " << std::endl;
//     animal->makeSound();

// 	delete cat;
// 	delete dog;
// 	delete animal;
    
// 	const WrongAnimal* wrong_cat = new WrongCat();
// 	std::cout << "wrong_cat Type: " << wrong_cat->getType() << " " << std::endl;
//     wrong_cat->makeSound();




// }
