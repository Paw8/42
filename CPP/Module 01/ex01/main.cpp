/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:34:17 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 15:29:20 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	one;
	int N = 10;
	
	one = zombieHorde(N, "Zombie");
	std::cout << "Adress of pointer:\t" << one << std::endl;
	std::cout << "Adress of 1st element:\t" << &one[0] << std::endl;
	std::cout << "Adress of 2nd element:\t" << &one[1] << std::endl;
	
	while (N--) {
		one[N].announce();
	}
	
	one[2].announce();
	one[5].setname("Random", 8);
	one[5].announce();
	
	delete []one;
	return 0;
}