/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:56:27 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 02:27:31 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	one;
	Zombie	two("Odin");

	one = new Zombie("Thor");
	randomChump("Loki");

	one->announce();
	two.announce();
	delete one;
	return 0;
}
