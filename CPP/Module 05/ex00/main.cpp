/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:18:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/20 18:12:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << std::endl;
	std::cout << "Creating Bureaucrat with a to high grade:" << std::endl;
	try {
		Bureaucrat	one("Pedro", -5);
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << "Creating Bureaucrat with a to low grade:" << std::endl;
	try {
		Bureaucrat	two("Ulli", 151);
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl;
	Bureaucrat	thor("Thor", 149);
	Bureaucrat	odin("Odin", 2);
	std::cout << GREEN << "Testing 'get functions':" << RESET << std::endl;
	std::cout << "getGrade: " << thor.getGrade() << "\t" << "getName: " << thor.getName() << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "Decrementing to 'under' 150:" << RESET << std::endl;
	std::cout << thor;
	try {
		thor.decrementGrade();
		std::cout << thor;
		thor.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << thor;
	std::cout << std::endl;
	
	std::cout << GREEN << "Incrementing to 'over' 1:" << RESET << std::endl;
	std::cout << odin;
	
	try {
		odin.incrementGrade();
		std::cout << odin;
		odin.incrementGrade();
		odin.incrementGrade();
		odin.incrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << odin;
	std::cout << std::endl;
	
	return 0;
}