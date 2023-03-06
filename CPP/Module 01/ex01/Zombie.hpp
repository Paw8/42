/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:35:11 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 14:35:19 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie {
		std::string	_name;
		size_t		_index;
	public:
		Zombie();
		~Zombie();
		void	setname(std::string name, size_t index);
		void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
