/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:06:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 13:06:17 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal& obj) : type(obj.type) {
	std::cout << "Animal Copy constructor called" << std::endl;
	return;
}

Animal&	Animal::operator=(const Animal& obj) {
	type = obj.type;
	std::cout << "Animal Assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
	return;
}

std::string	Animal::getType(void) const {
	return type;
}

void	Animal::makeSound(void) const {
	std::cout << RED << type << "s make sounds!" << RESET << std::endl;
	return;
}
