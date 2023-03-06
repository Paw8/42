/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:04:55 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/05 17:26:21 by pcordeir         ###   ########.fr       */
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