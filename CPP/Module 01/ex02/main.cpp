/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:33:08 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/03 15:45:16 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR;
	std::string& stringREF = str;

	stringPTR = &str;

	std::cout << std::setw(20) << std::right << &str << std::endl;
	std::cout << std::setw(20) << std::right << stringPTR << std::endl;
	std::cout << std::setw(20) << std::right << &stringREF << std::endl;
	
	std::cout << std::setw(20) << std::right << str << std::endl;
	std::cout << std::setw(20) << std::right << *stringPTR << std::endl;
	std::cout << std::setw(20) << std::right << stringREF << std::endl;

	return 0;	
}
