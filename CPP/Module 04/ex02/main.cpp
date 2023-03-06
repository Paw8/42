/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:59:08 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 18:05:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void) {
	int arr_size = 10;
	const Animal** const	animals = new const Animal*[arr_size];
	int n = 0;
	while (n < arr_size / 2) {
		animals[n] = new Cat();
		n++;
	}
	while (n < arr_size) {
		animals[n] = new Dog();
		n++;
	}
	std::cout << std::endl << RED << "Object construction done. Testing makeSound(): " << RESET << std::endl;
	
	while (--n >= 0)
		animals[n]->makeSound();
	std::cout << std::endl;
	
	std::cout << YELLOW << "Deleting cats and dogs in expected order: " << RESET << std::endl;
	while (++n < arr_size)
		delete animals[n];
	delete []animals;
	std::cout << std::endl;

	std::cout << RED << "Starting Deep Copy testing" << RESET << std::endl << std::endl;
	
	Dog	one;
	Dog	two(one);
	Dog three;
	std::cout << std::endl;

	std::cout << "Brain 1: "; one.getBrain(); std::cout << std::endl;
	std::cout << "Brain 2: "; two.getBrain(); std::cout << std::endl;
	std::cout << "Brain 3: "; three.getBrain(); std::cout << std::endl;
	one.setIdea("42");
	std::cout << YELLOW << "Changing Brain 1 to '42'" << RESET << std::endl;
	std::cout << "Brain 1: "; one.getBrain(); std::cout << std::endl;
	std::cout << "Brain 2: "; two.getBrain(); std::cout << std::endl;
	std::cout << "Brain 3: "; three.getBrain(); std::cout << RESET << std::endl;
	std::cout << YELLOW << "Assigning Brain 1 (42) to Brain 3: "; std::cout << CYAN << std::endl;
	three = one;
	std::cout << RESET << "Brain 1: "; one.getBrain(); std::cout << std::endl;
	std::cout << "Brain 2: "; two.getBrain(); std::cout << std::endl;
	std::cout << "Brain 3: "; three.getBrain(); std::cout << std::endl;
	one.setIdea("21");
	std::cout << YELLOW << "Changing Brain 1 again to '21'"; std::cout << RESET << std::endl;
	std::cout << "Brain 1: "; one.getBrain(); std::cout << std::endl;
	std::cout << "Brain 2: "; two.getBrain(); std::cout << std::endl;
	std::cout << "Brain 3: "; three.getBrain(); std::cout << std::endl;
	std::cout << std::endl << RED << "Destruction..." << RESET << std::endl;
	
	return 0;
}
