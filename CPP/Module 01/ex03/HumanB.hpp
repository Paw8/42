/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:50:44 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 11:51:38 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& temp);
		void	attack(void) const;
	private:
		std::string	name;
		Weapon*		weapon;
};

#endif