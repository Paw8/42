/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:09:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/02 16:34:34 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook closed" << std::endl;
	return;
}

int	PhoneBook::_oldest = 0;

void	PhoneBook::add(void) {
	int	index;

	index = 0;
	while (contact[index].check_empty() && index < 8)
		index++;
	if (index < 8)
		contact[index].addinfo();
	else {
		contact[_oldest].addinfo();
		if (++_oldest > 7)
			_oldest = 0;
	}
	return;
}

void	PhoneBook::search(void) const {
	int	index = 0;
	std::string	i;
	
	if (!contact[index].check_empty()) {
		std::cout << "PhoneBook empty" << std::endl;
		return;
	}
	else {
		while (contact[index].check_empty() && index < 8) {
			contact[index].printbook(index);
			index++;
		}
	}
	std::cout << "Enter Index Number (0 - 7): ";
	if (!std::getline(std::cin, i)) return;
	while (i != "0" && i != "1" && i != "2" && i != "3" && i != "4" && i != "5" && i != "6" && i != "7") {
		std::cout << "Please enter a valid Index (0 - 7): ";
		if (!std::getline(std::cin, i)) return;
	}
	index = i[0] - '0';
	if (contact[index].check_empty())
		contact[index].printcontact();
	else
		std::cout << "Contact empty" << std::endl;
	return;
}
