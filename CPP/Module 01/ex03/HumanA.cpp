/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:39:16 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/04 16:44:20 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& temp) : name(name),weapon(temp) {
	return;
}

HumanA::~HumanA() {
	return;
}

void	HumanA::attack(void) const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	return;
}