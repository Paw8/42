/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:19:27 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 11:39:39 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Empty"), hp(10), ep(10), dmg(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), dmg(0) {
	std::cout << "Default constructor called with name: " << name << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hp(obj.hp), ep(obj.ep), dmg(obj.dmg) {
	std::cout << "Copy constructor called" << std::endl;
	return;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj) {
	name = obj.name;
	hp = obj.hp;
	ep = obj.ep;
	dmg = obj.dmg;
	std::cout << "Assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor of " << name << " called" << std::endl;
	return;
}

void	ClapTrap::attack(const std::string& target) {
	if (hp <= 0) {
		std::cout << YELLOW << "ClapTrap " << name << " can't attack, because it's already dead!" << DEFAULT << std::endl;
	}
	else if (ep <= 0) {
		std::cout << YELLOW << "ClapTrap " << name << " doesn't have enough energy to attack!" << DEFAULT << std::endl;
	}
	else {
		std::cout << BLUE << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << dmg << " points of damage!" << DEFAULT << std::endl;
		ep--;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << RED << "ClapTrap " << name << " takes " << amount;
	std::cout << " points of damage!" << DEFAULT << std::endl;
	hp -= amount;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hp <= 0) {
		std::cout << YELLOW << "ClapTrap " << name << " can't repair itself, because it's already dead!" << DEFAULT << std::endl;
	}
	else if (ep <= 0) {
		std::cout << YELLOW << "ClapTrap " << name << " doesn't have enough energy to repair!" << DEFAULT << std::endl;
	}
	else {
		std::cout << GREEN << "ClapTrap " << name << " is being repaired for " << amount;
		std::cout << " Hit points!" << DEFAULT << std::endl;
		ep--;
		hp += amount;
	}
	return;
}