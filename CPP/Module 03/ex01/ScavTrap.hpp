/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:45 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap&	operator=(const ScavTrap& obj);
		~ScavTrap();
	
		void	getinfo(void) const;
		void	attack(const std::string& target);
		void	guardGate(void);
	private:
		bool	guardgate;
};

#endif
