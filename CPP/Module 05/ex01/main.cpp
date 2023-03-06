/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:18:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/24 17:23:14 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << std::endl << YELLOW << "<<<< Try creating Forms outside the limit >>>>" << RESET << std::endl;
	try {
		Form	a("Form A", 0, 1);
	} catch (const std::exception& e) {
		std::cerr << "Couldn't create Form A: " << RED << e.what() << RESET << std::endl;
	}
	try {
		Form	b("Form B", 151, 150);
	} catch (const std::exception& e) {
		std::cerr << "Couldn't create Form B: " << RED << e.what() << RESET << std::endl;
	}
	
	Bureaucrat	thor("Thor", 50);
	Bureaucrat	odin("Odin", 5);
	Form		a("Form A", 1, 1);
	Form		b("Form B", 10, 150);
	Form		c("Form C", 75, 100);

	std::cout << std::endl << YELLOW << "<<<< Testing 'signForm()' >>>>" << RESET << std::endl;
	odin.signForm(b);
	odin.signForm(a);
	odin.signForm(b);
	
	std::cout << std::endl << YELLOW << "<<<< Testing 'signForm()' >>>>" << RESET << std::endl;
	try {
		c.beSigned(thor);
		c.beSigned(odin);
		a.beSigned(odin);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}