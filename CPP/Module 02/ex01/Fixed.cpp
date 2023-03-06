/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:03:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/08 15:57:52 by pcordeir         ###   ########.fr       */
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

Fixed::Fixed(const int nbr) : fix_point_value(nbr<<bits) {
	std::cout << "Int constructor called" << std::endl;
	if (nbr < -8388608 || nbr > 8388607)
		std::cout << "Fixed out of range" << std::endl;
	return;
}

Fixed::Fixed(const float nbr) : fix_point_value(nbr * (1 << bits) + (nbr >= 0 ? 0.5 : -0.5)) {
	std::cout << "Float constructor called " << std::endl;
	if (int(nbr) - 1 < -8388608 || int(nbr) + 1 > 8388607)
		std::cout << "Fixed out of range" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& obj) : fix_point_value(obj.fix_point_value) {
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	fix_point_value = obj.fix_point_value;
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

float	Fixed::toFloat(void) const {
	return (float(fix_point_value) / (1 << bits));
}

int		Fixed::toInt(void) const {
	return (fix_point_value >> bits);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}