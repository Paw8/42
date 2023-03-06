/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:54 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 11:51:15 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanA {
	public:
		HumanA(std::string name, Weapon& temp);
		~HumanA();
		void	attack(void) const;
	private:
		std::string	name;
		Weapon&		weapon;
};
#endif
