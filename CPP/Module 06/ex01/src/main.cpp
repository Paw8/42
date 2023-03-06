/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 14:37:24 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int	main(void) {
	
	Data	mystruct;

	mystruct.i = 42;
	mystruct.c = 'W';
	mystruct.str = "Hello Wolfsburg!";
	
	std::cout << std::endl << "Adress of 'mystruct':" << std::endl;
	std::cout << GREEN << &mystruct << RESET << std::endl;
	
	uintptr_t	u_ptr = serialize(&mystruct);			//serializing adress
	Data*	ptr = deserialize(u_ptr);					//deserializing adress
	
	std::cout << "Adress of new generated pointer to 'mystruct':" << std::endl;
	std::cout << GREEN << ptr << RESET << std::endl << std::endl;
	
	std::cout << YELLOW << "<<<< Playing around with 'reinterpret_cast' >>>>" << RESET << std::endl;
	
	int*	i_ptr = reinterpret_cast<int*>(ptr);
	std::cout << i_ptr << std::endl;
	std::cout << *i_ptr << std::endl;
	
	char*	c_ptr = reinterpret_cast<char*>(++i_ptr);
	std::cout << c_ptr << std::endl;
	std::cout << *c_ptr << std::endl;
	
	std::string* str_ptr = reinterpret_cast<std::string*>(++i_ptr);
	std::cout << str_ptr << std::endl;
	std::cout << *str_ptr << std::endl;
	
	return 0;
}