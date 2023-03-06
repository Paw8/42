/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:17:18 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 13:14:25 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	std::cout << "Cat Copy constructor called" << std::endl;
	return;
}

Cat&	Cat::operator=(const Cat& obj) {
	Animal::operator=(obj);
	std::cout << "Cat Assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	return;
}

void	Cat::makeSound(void) const {
	std::cout << GREEN << type << "s purr!" << RESET << std::endl;
	return;
}
