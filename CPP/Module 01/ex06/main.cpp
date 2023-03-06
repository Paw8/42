/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:48:45 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/06 13:48:26 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv) {
	std::string	arg;
	Harl	one;
	if (argc == 2) {
		arg = argv[1];
		one.complain(arg);
	}
	else
		one.complain(arg);
	return 0;
}