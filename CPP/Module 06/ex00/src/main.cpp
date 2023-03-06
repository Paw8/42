/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 12:57:37 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		std::string	arg = argv[1];
		convert(arg);
	}
	else
		std::cout << RED << "Error: " << RESET << "'Converter' requires exactly 1 Argument (" << argc - 1 << " given)" << std::endl;
	return 0;
}