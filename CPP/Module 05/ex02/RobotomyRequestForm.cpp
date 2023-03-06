/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:59:29 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 16:44:55 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj), target(obj.target) {
	return;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	target = obj.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	return;
}

std::ostream&	RobotomyRequestForm::write(std::ostream& dest) const {
	dest << GREEN << "Name: " << this->getName() << " <" << this->getTarget() << ">" << std::endl << "Signed: ";
	if (this->getSigned())
		dest << "TRUE";
	else
		dest << "FALSE";
	dest << std::endl << "Grade to sign: " << this->getGrade_to_sign() << std::endl;
	dest << "Grade to execute: " << this->getGrade_to_exec() << RESET << std::endl;
	return dest;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return target;
}

void	RobotomyRequestForm::action(void) const {
	std::cout << "Drilling noise..." << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << GREEN << target << " has been robotomized." << RESET << std::endl;
	else
		std::cout << RED << "Robotomy of " << target << " failed!" << RESET << std::endl;
	return;
}
