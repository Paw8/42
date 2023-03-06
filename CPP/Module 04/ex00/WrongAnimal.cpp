/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:21:42 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 13:13:18 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	return;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& obj) {
	type = obj.type;
	std::cout << "WrongAnimal Assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
	return;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << RED << type << "s Muuuuuuuh?!?" << RESET << std::endl;
	return;
}
