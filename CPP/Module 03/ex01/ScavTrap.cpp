/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:26 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 11:53:58 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	hp = 100;
	ep = 50;
	dmg = 20;
	type = "ScavTrap";
	guardgate = false;
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hp = 100;
	ep = 50;
	dmg = 20;
	type = "ScavTrap";
	guardgate = false;
	std::cout << "ScavTrap Name constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	guardgate = obj.guardgate;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	return;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj) {
	ClapTrap::operator=(obj);
	guardgate = obj.guardgate;
	std::cout << "ScavTrap Assignment constructor called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor of " << name << " called" << std::endl;
	return;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << MAGENTA << "Being a " << type << " is awesome!" << std::endl;
	ClapTrap::attack(target);
	return;
}

void	ScavTrap::guardGate(void) {
	std::cout << CYAN << "ScavTrap " << name << " is now in Gate keeper mode!" << DEFAULT << std::endl;
	guardgate = true;
	return;
}

void	ScavTrap::getinfo(void) const {
	if (guardgate)
		std::cout << CYAN << "Access denied! " << type << " " << name << " is in Gate keeper mode!" << DEFAULT << std::endl;
	else
		ClapTrap::getinfo();
	return;
}
