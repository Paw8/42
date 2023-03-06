/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:56:01 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 18:04:32 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	ptr = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
	return;
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	ptr = new Brain(*obj.ptr);
	std::cout << "Dog Copy constructor called" << std::endl;
	return;
}

Dog&	Dog::operator=(const Dog& obj) {
	Animal::operator=(obj);
	ptr = &(ptr->operator=(*obj.ptr));
	std::cout << "Dog Assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete ptr;
	return;
}

void	Dog::makeSound(void) const {
	std::cout << GREEN << type << "s bark!" << RESET << std::endl;
	return;
}

void	Dog::getBrain(void) const {
	ptr->getIdea();
	return;
}

void	Dog::setIdea(std::string idea) {
	ptr->setIdea(idea);
	return;
}
