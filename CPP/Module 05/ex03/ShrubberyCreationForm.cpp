/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:40:14 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 17:49:50 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <unistd.h>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj), target(obj.target) {
	return;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	target = obj.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	return;
}

std::ostream&	ShrubberyCreationForm::write(std::ostream& dest) const {
	dest << GREEN << "Name: " << this->getName() << " <" << this->getTarget() << ">" << std::endl << "Signed: ";
	if (this->getSigned())
		dest << "TRUE";
	else
		dest << "FALSE";
	dest << std::endl << "Grade to sign: " << this->getGrade_to_sign() << std::endl;
	dest << "Grade to execute: " << this->getGrade_to_exec() << RESET << std::endl;
	return dest;
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return target;
}

void	ShrubberyCreationForm::action(void) const {
	std::string	temp = target;
	temp.append(".shrubbery");
	std::ofstream	file(temp.c_str());
	file << "			  _{\\ _{\\{\\/}/}/}__" << std::endl;
	file << "			 {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "			{/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file << "		 {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file << "		{/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "	   _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "	  {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "	  _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "	 {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "	  {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "	   {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "	  {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "	   {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "		 {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "		  (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file << "			{/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "			 {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
	file << "			  {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "			  (_)  \\.-'.-/" << std::endl;
	file << "		  __...--- |'-.-'| --...__" << std::endl;
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	file << " -\"    ' .  . '    |.'-._| '  . .  '   -." << std::endl;
	file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	file << "		  ' ..     |'-_.-|" << std::endl;
	file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	file << "			  .'   |'- .-|   '." << std::endl;
	file << " ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
	file << "  .-' '        '-._______.-'     '  ." << std::endl;
	file << "	   .      ~," << std::endl;
	file << "   .       .   |\\   .    ' '-." << std::endl;
	file << "   ___________/  \\____________" << std::endl;
	file << "  /  Why is it, when you want \\" << std::endl;
	file << " |  something, it is so damn   |" << std::endl;
	file << " |    much work to get it?     |" << std::endl;
	file << "  \\___________________________/" << std::endl;
	file.close();
	return;
}
