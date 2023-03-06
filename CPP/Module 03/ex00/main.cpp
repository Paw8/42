/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:19:55 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 11:41:43 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	one("Odin");
	ClapTrap	two("Thor");

	std::cout << std::endl;
	one.attack("\"This could be anything\"");
	one.attack("Loki");
	one.takeDamage(10);
	
	one.attack("Thor");
	one.beRepaired(10);
	
	std::cout << std::endl << "Wasting Energy..." << std::endl;
	
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);
	two.beRepaired(10);

	two.takeDamage(109);
	
	two.beRepaired(10);
	two.attack("Odin");
	std::cout << std::endl;
	return 0;
}
