/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:34:25 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/27 20:54:53 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : size(N), vec(0) {
	return;
}

Span::Span(const Span& obj) : size(obj.size), vec(obj.vec) {
	return;
}

Span&	Span::operator=(const Span& obj) {
	if (this == &obj)
		return *this;
	size = obj.size;
	vec = obj.vec;
	return *this;
}

Span::~Span() {
	return;
}

void	Span::addNumber(int nbr) {
	if (vec.size() >= size)
		throw OutOfBounds();
	vec.push_back(nbr);
}

void	Span::addRNG(int amount) {
	if (amount <= 0) {
		std::cout << "Amount has to be greater then 0." << std::endl;
		return;
	}
	srand(time(NULL));
	for (int i = 0; i < amount; i++) {
		if (rand() % 2)
			addNumber(rand());
		else
			addNumber(rand() - RAND_MAX);
	}
	return;
}

unsigned int	Span::getSize(void) const {
	return size;
}

const char*	Span::OutOfBounds::what() const throw() {
	return "Span out of bounds!";
}

const char*	Span::NotEnoughElements::what() const throw() {
	return "Not enough Elements to find span!";
}

unsigned int	Span::longestSpan(void) const {
	if (vec.size() < 2)
		throw NotEnoughElements();
	return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}

unsigned int	Span::shortestSpan(void) {
	if (vec.size() < 2)
		throw NotEnoughElements();
	std::sort(vec.begin(), vec.end());
	unsigned int	dif = static_cast<unsigned int>(*(vec.begin() + 1) - *vec.begin());
	for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++) {
		if (static_cast<unsigned int>(*it - *(it - 1)) < dif)
			dif = static_cast<unsigned int>(*it - *(it - 1));
	}
	return dif;
}

void	Span::print(void) {
	int nl = 1;
	for (std::vector<int>::iterator	it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
		if (!(nl++ % 10))
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
