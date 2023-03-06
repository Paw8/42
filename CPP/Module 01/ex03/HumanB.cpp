/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:53:31 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/05 11:44:58 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name),weapon(NULL) {
	return;
}

HumanB::~HumanB() {
	return;
}

void	HumanB::setWeapon(Weapon& temp) {
	weapon = &temp;
	return;
}

void	HumanB::attack(void) const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no Weapon to attack with!" << std::endl;
	return;
}