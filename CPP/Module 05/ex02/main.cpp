/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:18:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 19:50:48 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	ShrubberyCreationForm	home("Home");
	RobotomyRequestForm		robot("Robot");
	PresidentialPardonForm	betel("Betelgeusian");

	std::cout << std::endl << YELLOW << "<<<< Forms Information >>>>" << RESET << std::endl;
	std::cout << home;
	std::cout << robot;
	std::cout << betel;

	std::cout << std::endl << YELLOW << "<<<< Function execute() >>>>" << RESET << std::endl;
	Bureaucrat	one("One", 1);
	Bureaucrat	two("Two", 138);
	ShrubberyCreationForm	work("Work");
	try {
		home.execute(one);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	one.signForm(home);
	try {
		home.execute(two);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try {
		home.execute(one);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	two.signForm(work);
	try {
		work.execute(one);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << YELLOW << "<<<< Function executeForm() >>>>" << RESET << std::endl;
	try {
		one.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	one.signForm(robot);
	try {
		two.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try {
		one.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try {
		one.executeForm(betel);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	one.signForm(betel);
	try {
		one.executeForm(betel);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	return 0;
}