/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:09:56 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 15:05:57 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw myException("Grade too high!");
	if (grade > 150)
		throw myException("Grade too low!");
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade) {
	return;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this == &obj)
		return *this;
	this->~Bureaucrat();
	new (this)Bureaucrat(obj);
	return *this;
}

Bureaucrat::~Bureaucrat() {
	return;
}

std::string	Bureaucrat::getName(void) const {
	return name;
}

int	Bureaucrat::getGrade(void) const {
	return grade;
}

void	Bureaucrat::decrementGrade(void) {
	if (grade >= 150)
		throw myException("Grade too low!");
	grade++;
	return;
}

void	Bureaucrat::incrementGrade(void) {
	if (grade <= 1)
		throw myException("Grade too high!");
	grade--;
	return;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (out);
}

void	Bureaucrat::signForm(Form& f_obj) {
	if (f_obj.getSigned())
		std::cout << "Form already signed!" << std::endl;
	else
		f_obj.beSigned(*this);
}

void	Bureaucrat::executeForm(const Form& form) {
	if (this->getGrade() > form.getGrade_to_exec())
		std::cout << "Grade to low to execute!" << std::endl;
	else if (!form.getSigned())
		std::cout << "Form not signed!" << std::endl;
	else
		form.execute(*this);
}
