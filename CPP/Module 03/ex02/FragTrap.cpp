/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:54:24 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 12:08:21 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hp = 100;
	ep = 100;
	dmg = 30;
	type = "FragTrap";
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hp = 100;
	ep = 100;
	dmg = 30;
	type = "FragTrap";
	std::cout << "FragTrap Name constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	return;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj) {
	ClapTrap::operator=(obj);
	std::cout << "FragTrap Assignment constructor called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor of " << name << " called" << std::endl;
	return;
}

void	FragTrap::highFivesGuys(void) const {
	std::cout << YELLOW << type << " " << name << ": High 5 guys!" << DEFAULT << std::endl;
	return;
}
