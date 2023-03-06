/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:28:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 14:17:45 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
	return;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj) {
	WrongAnimal::operator=(obj);
	std::cout << "WrongCat Assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
	return;
}

void	WrongCat::makeSound(void) const {
	std::cout << MAGENTA << "Can't be called by pointer to base class!" << RESET << std::endl;
	return;
}
