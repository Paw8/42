/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:21:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/02 22:31:14 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::printfstring(std::string info) const {
	if (info.length() > 10) {
		info.resize(9);
		info.push_back('.');
		std::cout << std::setw(10) << std::right << info << "|";
	}
	else 
		std::cout << std::setw(10) << std::right << info << "|";
	return;
}

void	Contact::addinfo(void) {
	std::cout << "Enter First Name: ";
	if (!std::getline(std::cin, name)) return;
	while (name.empty()) {
		std::cout << "First Name can't be empty!" << std::endl;
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, name)) return;
	}
	std::cout << "Enter Last Name: ";
	if (!std::getline(std::cin, last_name)) return;
	while (last_name.empty()) {
		std::cout << "Last Name can't be empty!" << std::endl;
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, last_name)) return;
	}
	std::cout << "Enter Nickname: ";
	if (!std::getline(std::cin, nickname)) return;
	while (nickname.empty()) {
		std::cout << "Nickame can't be empty!" << std::endl;
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, nickname)) return;
	}
	std::cout << "Enter Phone Number: ";
	if (!std::getline(std::cin, phone_number)) return;
	while (phone_number.empty()) {
		std::cout << "Phone Number can't be empty!" << std::endl;
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, phone_number)) return;
	}
	std::cout << "Enter Darkest Secret: ";
	if (!std::getline(std::cin, darkest_secret)) return;
	while (darkest_secret.empty()) {
		std::cout << "Darkest Secret can't be empty!" << std::endl;
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, darkest_secret)) return;
	}
	return;
}

bool	Contact::check_empty(void) const {
	if (name.empty())
		return false;
	return true;
}

void	Contact::printbook(int index) const {
	if (!index) {
		std::cout << "|";
		printfstring("Index");
		printfstring("First Name");
		printfstring("Last Name");
		printfstring("Nickname");
		std::cout << std::endl;
	}
	std::cout << "|" << std::setw(10) << std::right << index << "|";
	printfstring(name);
	printfstring(last_name);
	printfstring(nickname);
	std::cout << std::endl;
}

void	Contact::printcontact(void) const {
	std::cout << name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
	return;
}
