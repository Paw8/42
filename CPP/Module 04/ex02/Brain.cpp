/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:12 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 17:10:05 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty";
	std::cout << "Brain Default constructor called " << std::endl;
	return;
}

Brain::Brain(const Brain& obj) {
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	std::cout << "Brain Copy constructor called" << std::endl;
	return;
}

Brain&	Brain::operator=(const Brain& obj) {
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	std::cout << "Brain Assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
	return;
}

void	Brain::setIdea(std::string idea) {
	for (int i = 0; i < 100; i++)
		ideas[i] = idea;
	return;
}

void	Brain::getIdea(void) const {
	// for (int i = 0; i < 100; i++)
		// std::cout << ideas[i] << std::endl;
	std::cout << ideas[0];
	return;
}
