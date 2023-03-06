/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:18:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/02 16:29:34 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	book;
	std::string	arg;

	std::cout << "You are now in the main menu." << std::endl;
	std::cout << "Available commands are: ADD | SEARCH | EXIT" << std::endl;
	std::cout << "Enter command: ";
	while (std::getline(std::cin, arg) && arg != "EXIT") {
		// if (arg == "EXIT")
		// 	break;
		if (arg == "ADD")
			book.add();
		else if (arg == "SEARCH")
			book.search();
		else
			std::cout << "Invalid Command" << std::endl;
		if (!std::cin.good()) break;
		std::cout << "You are now in the main menu." << std::endl;
		std::cout << "Available commands are: ADD | SEARCH | EXIT" << std::endl;
		std::cout << "Enter command: ";
	}
	if (arg == "EXIT")
		return 0;
	else {
		std::cout << std::endl << "<<<<< ERROR! >>>>> Standard input stream was closed!" << std::endl;
		return (1);
	}
}