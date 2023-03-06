/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:19:55 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/14 11:54:23 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	one("Odin");
	ScavTrap	test("Thor");
	
	std::cout << std::endl;
	
	test.attack("Loki");
	std::cout << std::endl;
	one.attack("Thor and Loki");
	one.getinfo();
	test.getinfo();
	test.guardGate();
	test.getinfo();

	std::cout << std::endl;
	
	return 0;
}
