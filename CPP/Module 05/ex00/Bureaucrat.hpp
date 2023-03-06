/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:01:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/20 17:14:57 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RESET		"\033[0m"
# define GREY		"\033[0m\033[90m"
# define RED		"\033[0m\033[91m"
# define GREEN		"\033[0m\033[92m"
# define YELLOW		"\033[0m\033[93m"
# define BLUE		"\033[0m\033[94m"
# define MAGENTA	"\033[0m\033[95m"
# define CYAN		"\033[0m\033[96m"
# define WHITE		"\033[0m\033[97m"

# include <iostream>
# include <string>
# include "myException.hpp"

/*	To inherit class myException Constructors and Destructors must be adjusted accordingly */

class	Bureaucrat {											// : public myException {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();											// virtual ~Bureaucrat() throw ();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		
	private:
		const std::string	name;
		int					grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
