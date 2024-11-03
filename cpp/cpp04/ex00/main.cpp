/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:50:43 by cliew             #+#    #+#             */
/*   Updated: 2024/11/03 13:43:52 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main( void )
{
    std::cout << "--------------- Animal ---------------" << std::endl;

    const Animal* animal = new Animal();
    // const Animal* j = new Dog();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    std::cout << "cat Type: " << cat->getType() << " " << std::endl;
    cat->makeSound();

	std::cout << "dog Type: " << dog->getType() << " " << std::endl;
    dog->makeSound();

 	std::cout << "animal Type: " << animal->getType() << " " << std::endl;
    animal->makeSound();

	delete cat;
	delete dog;
	delete animal;
    
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "wrong_cat Type: " << wrong_cat->getType() << " " << std::endl;
    wrong_cat->makeSound();




}
// int main( void )
// {
//     std::cout << "--------------- Animal ---------------" << std::endl;

//     const Animal* animal = new Animal();
//     // const Animal* j = new Dog();
//     const Animal* cat = new Cat();
// 	const Animal* cat2 = cat; 

// 	const Animal* cat3 = new Animal("Not cat");
// 	std::cout << "cat3 Type: " << cat3->getType() << " " << std::endl;
// 	cat3=cat; 

//     // std::cout << "J Type: " << j->getType() << " " << std::endl;
// 	std::cout << "animal Type: " << animal->getType() << " " << std::endl;

//     std::cout << "cat Type: " << cat->getType() << " " << std::endl;
//     cat->makeSound();
//     animal->makeSound();

//     std::cout << "cat2 Type: " << cat2->getType() << " " << std::endl;
//     cat2->makeSound();

// 	std::cout << "cat3 Type: " << cat3->getType() << " " << std::endl;
//     cat3->makeSound();



// }