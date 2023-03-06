/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:39:25 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 13:58:25 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	temp;

	temp = new Zombie[N];
	while (N--) {
		temp[N].setname(name, N);
		// temp[N].announce();
	}
	return (temp);
}