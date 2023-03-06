/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:52:00 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 22:02:58 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class	Intern {
	public:
		Intern();
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern();

		Form*	makeForm(std::string form, std::string target) const;
		Form*	shrubbery(std::string target) const;
		Form*	robotomy(std::string target) const;
		Form*	presidential(std::string target) const;
};

#endif
