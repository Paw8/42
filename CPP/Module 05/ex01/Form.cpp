/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:24:58 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 00:47:48 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grade_s, int grade_e) : name(name), is_signed(false), grade_to_sign(grade_s), grade_to_exec(grade_e) {
	if (grade_s > 150 || grade_e > 150)
		throw myException("Grade too low!");
	if (grade_s < 1 || grade_e < 1)
		throw myException("Grade to high!");
	return;
}

Form::Form(const Form& obj) : name(obj.name), is_signed(obj.is_signed), grade_to_sign(obj.grade_to_sign), grade_to_exec(obj.grade_to_exec) {
	return;
}

Form&	Form::operator=(const Form& obj) {
	if (this == &obj)
		return *this;
	this->~Form();
	new (this)Form(obj);
	return *this;
}

Form::~Form() {
	return;
}

std::ostream&	operator<<(std::ostream& out, const Form& obj) {
	out << GREEN << "Name: " << obj.getName() << std::endl << "Signed: ";
	if (obj.getSigned())
		out << "TRUE";
	else
		out << "FALSE";
	out << std::endl << "Grade to sign: " << obj.getGrade_to_sign() << std::endl;
	out << "Grade to execute: " << obj.getGrade_to_exec() << RESET << std::endl;
	return out;	
}

std::string	Form::getName(void) const {
	return name;
}

bool	Form::getSigned(void) const {
	return is_signed;
}

int	Form::getGrade_to_sign(void) const {
	return grade_to_sign;
}

int	Form::getGrade_to_exec(void) const {
	return grade_to_exec;
}

void	Form::beSigned(const Bureaucrat& b_obj) {
	if (is_signed)
		std::cout << "Form already signed!" << std::endl;
	else if (grade_to_sign < b_obj.getGrade())
		throw myException("Grade too low!");
	else {
		is_signed = true;
		std::cout << b_obj.getName() << " signed " << name << std::endl;
	}
}
