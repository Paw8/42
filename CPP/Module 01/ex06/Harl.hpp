/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:49:54 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 13:16:20 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl;

typedef struct	s_event {
	std::string		str[4];
	void			(Harl::*f[4])(void) const;
}t_event;

class	Harl {
	public:
		Harl();
		~Harl();
		void	complain(std::string level) const;
	private:
		void	debug(void) const;
		void	warning(void) const;
		void	info(void) const;
		void	error(void) const;
		t_event	arr;
};

#endif
