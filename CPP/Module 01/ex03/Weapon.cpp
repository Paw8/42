/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:27:19 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/04 16:42:52 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
	return;
}

Weapon::~Weapon() {
	return;
}

const std::string&	Weapon::getType(void) const {
	return type;
}

void	Weapon::setType(std::string type) {
	this->type = type;
	return;
}