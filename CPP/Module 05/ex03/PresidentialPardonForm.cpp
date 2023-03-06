/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:43:10 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 14:36:25 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj), target(obj.target) {
	return;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	target = obj.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	return;
}

std::ostream&	PresidentialPardonForm::write(std::ostream& dest) const {
	dest << GREEN << "Name: " << this->getName() << " <" << this->getTarget() << ">" << std::endl << "Signed: ";
	if (this->getSigned())
		dest << "TRUE";
	else
		dest << "FALSE";
	dest << std::endl << "Grade to sign: " << this->getGrade_to_sign() << std::endl;
	dest << "Grade to execute: " << this->getGrade_to_exec() << RESET << std::endl;
	return dest;	
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return target;
}

void	PresidentialPardonForm::action(void) const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return;
}
