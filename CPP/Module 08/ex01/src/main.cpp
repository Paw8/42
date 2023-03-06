/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/28 11:06:12 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	srand(time(0));
	std::cout << std::endl << YELLOW << "Creating Span one..." << RESET << std::endl;
	Span	one(rand() % 100 + 1);
	std::cout << "Size of Span two: " << MAGENTA << one.getSize() << RESET << std::endl;
	try {
		one.addRNG(50);
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Span one: " << RESET << std::endl;
	one.print();
	std::cout << CYAN << "Longest Span: " << RESET << one.longestSpan() << std::endl;
	std::cout << CYAN << "Shortest Span: " << RESET << one.shortestSpan() << std::endl;
	
	std::cout << std::endl << YELLOW << "Creating Span two..." << RESET << std::endl;
	Span	two(rand() % 50000 + 1);
	std::cout << "Size of Span two: " << MAGENTA << two.getSize() << RESET << std::endl;
	try {
		two.addRNG(rand());
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "Longest Span: " << RESET << two.longestSpan() << std::endl;
	std::cout << CYAN << "Shortest Span: " << RESET << two.shortestSpan() << std::endl;
	
	std::cout << std::endl << YELLOW << "<<<< Test case eval sheet >>>>" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
    return 0;
}
