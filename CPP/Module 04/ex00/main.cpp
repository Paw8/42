/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:59:08 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 13:21:21 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal*	meta = new Animal();
	const Animal*	milo = new Dog();
	const Animal*	tabby = new Cat();
	std::cout << std::endl;
	std::cout << GREEN << "Calling getType():" << std::endl << std::endl << RESET << "Milo: ";
	std::cout << GREEN << milo->getType() << RESET << std::endl << "Tabby: ";
	std::cout << GREEN << tabby->getType() << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "Calling makeSound():" << RESET << std::endl << std::endl;
	std::cout << "Milo is a Dog. "; milo->makeSound();
	std::cout << "Tabby is a Cat. "; tabby->makeSound(); std::cout << std::endl;
	
	std::cout << "Meta is a random Animal. "; meta->makeSound(); std::cout << std::endl;
	
	delete tabby;
	delete milo;
	delete meta;
	std::cout << std::endl << YELLOW << "Wrong Class testing >>>>" << RESET << std::endl << std::endl;
	
	const WrongCat		test;
	const WrongAnimal*	jan = new WrongCat();
	const WrongAnimal*	wrong = new WrongAnimal();
	std::cout << std::endl;
	
	std::cout << GREEN << "Calling getType():" << std::endl << std::endl << RESET << "Jan: ";
	std::cout << GREEN << jan->getType() << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "Calling makeSound():" << RESET << std::endl << std::endl;
	std::cout << "Jan is a WrongCat. "; jan->makeSound(); std::cout << std::endl;

	std::cout << "Wrong is a random WrongAnimal. "; wrong->makeSound(); std::cout << std::endl;
	std::cout << std::endl; test.makeSound(); std::cout << std::endl;

	
	delete wrong;
	delete jan;
	return 0;
}
