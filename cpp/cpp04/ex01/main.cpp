/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:43 by cliew             #+#    #+#             */
/*   Updated: 2024/11/08 21:49:37 by cliew            ###   ########.fr       */
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
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }
	Dog basic;
	{
	Dog tmp = basic;
	}
	Cat basic2;
	{
	Cat tmp2 = basic2;
	}

    return 0;

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
