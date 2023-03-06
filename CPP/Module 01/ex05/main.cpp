/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:51:46 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 13:52:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void) {
	
	std::string level;
	Harl	one;

	level = "DEBUG";
	one.complain(level);
	level = "INFO";
	one.complain(level);
	level = "WARNING";
	one.complain(level);
	level = "ERROR";
	one.complain(level);
	level = "default";
	one.complain(level);
	
	return 0;
}
