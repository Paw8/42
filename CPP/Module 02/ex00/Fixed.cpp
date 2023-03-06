/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:03:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/07 15:39:01 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed() : fix_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& obj) : fix_point_value(obj.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
	// obj.getRawBits();
	// fix_point_value = obj.getRawBits();
	return;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	fix_point_value = obj.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fix_point_value;
}

void	Fixed::setRawBits(const int raw) {
	fix_point_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
	return;
}
