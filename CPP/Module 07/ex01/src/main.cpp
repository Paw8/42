/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/26 20:16:50 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome {
	public:
		Awesome(void) : _n(42) {
			return;
		}
		int get(void) const {
			return this->_n;
		}
	private:
		int _n;
};

std::ostream & operator<<(std::ostream& o, const Awesome& rhs) {
	o << rhs.get();
	return o;
}

void addone(int& a) {
	a++;
}

void capitalization(char& c) {
	c = std::toupper(c);
	return;
}

template <typename T>
void print(const T& x) {
	std::cout << x << " ";
	return;
}

int main(void) {
	int length = 5;
	int num[5] = {1, 2, 3, 4, 5};
	char letter[5] = {'a', 'b', '1', '!', 'f'};
	std::cout << RED << "--- removed new line from print() ---" << RESET << std::endl;

	std::cout << std::endl << CYAN << "<<<< Function iter() and print() on num array >>>>" << RESET << std::endl;
	iter(num, length, print);
	std::cout << std::endl << "Executing Function addone() on num array..." << std::endl;
	iter(num, length, addone);
	std::cout << GREEN << "num array is now: " << RESET;
	iter(num, length, print);
	std::cout << std::endl;
	
	std::cout << std::endl << CYAN << "<<<< Function iter() and print() on letter array >>>>" << RESET << std::endl;
	iter(letter, length, print);
	std::cout << std::endl << "Executing Function capitalization() on letter array..." << std::endl;
	iter(letter, length, capitalization);
	std::cout << GREEN << "letter array is now: " << RESET;
	iter(letter, length, print);
	std::cout << std::endl;

	std::cout << std::endl << YELLOW << "<<<< Testing with the Awesome class from the eval sheet >>>>" << RESET << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	std::cout << GREEN << "Number array from eval sheet: " << RESET;
	iter(tab, length, print);
	std::cout << std::endl;
	std::cout << GREEN << "Awesome class array: " << RESET;
	iter(tab2, length, print);
	std::cout << std::endl << std::endl;

	return (0);
}
