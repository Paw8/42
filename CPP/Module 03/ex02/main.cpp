/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:19:55 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/15 13:02:51 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	FragTrap	first("Odin");
	FragTrap	second("Loki");
	std::cout << std::endl;

	first.highFivesGuys();
	first.attack("Thor");
	first.takeDamage(20);
	first.beRepaired(5);
	first.getinfo();
	second.highFivesGuys();
	second.getinfo();

	std::cout << std::endl;
	return 0;
}
