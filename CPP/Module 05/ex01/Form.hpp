/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:18:44 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/21 11:01:55 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	public:
		Form(std::string name, int grade_s, int grade_e);
		Form(const Form& obj);
		Form&	operator=(const Form& obj);
		~Form();

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGrade_to_sign(void) const;
		int			getGrade_to_exec(void) const;
		void		beSigned(const Bureaucrat& b_obj);

	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_exec;		
};

std::ostream&	operator<<(std::ostream& out, const Form& obj);

#endif
