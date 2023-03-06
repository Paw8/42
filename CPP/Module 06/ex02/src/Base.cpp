/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:41:36 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 17:45:53 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	generate(void) {
	int rng = rand();
	srand(time(NULL) + rng);
	if (rand() % 3 == 2)
		return new A;
	else if (rand() % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	else
		return;
}

void	identify(Base& p) {
	// Base	what;
	try {
		Base	what = dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	} catch (std::exception& e) {}
	
	try {
		Base	what = dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	} catch (std::exception& e) {}
	
	try {
		Base	what = dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	} catch (std::exception& e) {}
}
