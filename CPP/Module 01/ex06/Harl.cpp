/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:16:32 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 13:36:23 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl () {
	arr.str[0] = "DEBUG";
	arr.str[1] = "INFO";
	arr.str[2] = "WARNING";
	arr.str[3] = "ERROR";
	arr.f[0] = &Harl::debug;
	arr.f[1] = &Harl::info;
	arr.f[2] = &Harl::warning;
	arr.f[3] = &Harl::error;
	return;
}

Harl::~Harl () {
	return;
}

void	Harl::complain(std::string level) const {
	int i = 0;

	while (i < 4 && level != arr.str[i])
		i++;
	switch (i) {
		case 0:
			while (i < 4) {
				(this->*(arr.f[i]))();
				i++;
			}
			break;
		case 1:
			while (i < 4) {
				(this->*(arr.f[i]))();
				i++;
			}
			break;
		case 2:
			while (i < 4) {
				(this->*(arr.f[i]))();
				i++;
			}
			break;
		case 3:
			while (i < 4) {
				(this->*(arr.f[i]))();
				i++;
			}
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return;
}

void	Harl::debug(void) const {
	std::cout << "<<<< DEBUG >>>>" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return;
}

void	Harl::info(void) const {
	std::cout << "<<<< INFO >>>>" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}

void	Harl::warning(void) const {
	std::cout << "<<<< WARNING >>>>" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}

void	Harl::error(void) const {
	std::cout << "<<<< ERROR >>>>" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}