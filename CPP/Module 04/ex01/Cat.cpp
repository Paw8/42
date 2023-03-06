/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:17:18 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 16:57:58 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
	type = "Cat";
	ptr = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	ptr = new Brain(*obj.ptr);
	std::cout << "Cat Copy constructor called" << std::endl;
	return;
}

Cat&	Cat::operator=(const Cat& obj) {
	Animal::operator=(obj);
	ptr = &(ptr->operator=(*obj.ptr));
	std::cout << "Cat Assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete ptr;
	return;
}

void	Cat::makeSound(void) const {
	std::cout << GREEN << type << "s purr!" << RESET << std::endl;
	return;
}

void	Cat::getBrain(void) const {
	ptr->getIdea();
	return;
}

void	Cat::setIdea(std::string idea) {
	ptr->setIdea(idea);
	return;
}
