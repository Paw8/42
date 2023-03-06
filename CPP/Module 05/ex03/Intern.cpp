/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:57:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/24 17:44:09 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	return;
}

Intern::Intern(const Intern& obj) {
	(void)obj;
	return;
}

Intern&	Intern::operator=(const Intern& obj) {
	if (this == &obj)
		return *this;
	this->~Intern();
	new (this)Intern(obj);
	return *this;
}

Intern::~Intern() {
	return;
}

Form*	Intern::makeForm(std::string form, std::string target) const {
	int i = 0;
	std::string	forms[3] =	{"presidential pardon",
							"robotomy request",
							"shrubbery creation"};
	Form*	(Intern::*f[3])(std::string) const =	{&Intern::presidential,
													&Intern::robotomy,
													&Intern::shrubbery};
	while (i < 3 && form != forms[i])
		i++;
	if (i < 3) {
		std::cout << CYAN << "Intern creates " << form << " form." << RESET << std::endl;
		return (this->*f[i])(target);
	}
	std::cout << RED << "No such Form: " << form << RESET << std::endl;
	return 0;
}

Form*	Intern::presidential(std::string target) const {
	return new PresidentialPardonForm(target);
}

Form*	Intern::robotomy(std::string target) const {
	return new RobotomyRequestForm(target);
}

Form*	Intern::shrubbery(std::string target) const {
	return new ShrubberyCreationForm(target);
}
