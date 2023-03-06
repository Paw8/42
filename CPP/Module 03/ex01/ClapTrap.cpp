/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:19:27 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 11:52:54 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Empty"), hp(10), ep(10), dmg(0), type("ClapTrap") {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), dmg(0), type("ClapTrap") {
	std::cout << "ClapTrap Name constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hp(obj.hp), ep(obj.ep), dmg(obj.dmg), type(obj.type) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	return;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj) {
	name = obj.name;
	hp = obj.hp;
	ep = obj.ep;
	dmg = obj.dmg;
	type = obj.type;
	std::cout << "ClapTrap Assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor of " << name << " called" << std::endl;
	return;
}

void	ClapTrap::attack(const std::string& target) {
	if (hp <= 0) {
		std::cout << YELLOW << type << " " << name << " can't attack, because it's already dead!" << DEFAULT << std::endl;
	}
	else if (ep <= 0) {
		std::cout << YELLOW << type << " " << name << " doesn't have enough energy to attack!" << DEFAULT << std::endl;
	}
	else {
		if (type == "ClapTrap")
			std::cout << BLUE;
		std::cout << type << " " << name << " attacks " << target;
		std::cout << ", causing " << dmg << " points of damage!" << std::endl;
		ep--;
		std::cout << "Remaining energy points: " << ep << DEFAULT << std::endl;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << RED << type << " " << name << " takes " << amount;
	std::cout << " points of damage! " << std::endl;
	hp -= amount;
	if (hp <= 0)
		std::cout << type << " " << name << " died!" << DEFAULT << std::endl;
	else
		std::cout << "Remaining hit points: " << hp << DEFAULT << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hp <= 0) {
		std::cout << YELLOW << type << " " << name << " can't repair itself, because it's already dead!" << DEFAULT << std::endl;
	}
	else if (ep <= 0) {
		std::cout << YELLOW << type << " " << name << " doesn't have enough energy to repair!" << DEFAULT << std::endl;
	}
	else {
		std::cout << GREEN << type << " " << name << " is being repaired for " << amount;
		std::cout << " hit points!" << std::endl;
		ep--;
		hp += amount;
		std::cout << "New hit points: " << hp << std::endl << "Remaining energy points: " << ep << DEFAULT << std::endl;
	}
	return;
}

void	ClapTrap::getinfo(void) const {
	std::cout << std::endl << RED << "\t<<<< " << type << ": " << name << " >>>>" << std::endl;
	std::cout << MAGENTA << "\tHit points: " << hp << std::endl;
	std::cout << "\tEnergy points: " << ep << std::endl;
	std::cout << "\tDamage: " << dmg << DEFAULT << std::endl << std::endl;
	return;
}
