/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:34:46 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 14:31:21 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << _name << " " << _index << " says goodbye!" << std::endl;
	return;
}

void	Zombie::setname(std::string name, size_t index) {
	_name = name;
	_index = index;
	return;
}

void	Zombie::announce(void) const {
	std::cout << _name << " " << _index << " says hello!" << std::endl;
	return;
}
