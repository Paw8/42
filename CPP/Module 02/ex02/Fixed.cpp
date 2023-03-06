/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:03:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/10 12:33:34 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed() {
	return;
}

Fixed::Fixed() : fix_point_value(0) {
	return;
}

Fixed::Fixed(const int nbr) : fix_point_value(nbr<<bits) {
	// if (nbr < -8388608 || nbr > 8388607)
	// 	std::cout << "Fixed out of range" << std::endl;
	return;
}

Fixed::Fixed(const float nbr) : fix_point_value(nbr * (1 << bits) + (nbr >= 0 ? 0.5 : -0.5)) {
	// if (int(nbr) - 1 < -8388608 || int(nbr) + 1 > 8388607)
	// 	std::cout << "Fixed out of range" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& obj) : fix_point_value(obj.fix_point_value) {
	return;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	fix_point_value = obj.fix_point_value;
	return *this;
}

int	Fixed::getRawBits(void) const {
	return fix_point_value;
}

void	Fixed::setRawBits(const int raw) {
	fix_point_value = raw;
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

//	comparison

bool	Fixed::operator>(const Fixed& obj) const {
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const {
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed& obj) const {
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return (this->getRawBits() != obj.getRawBits());
}

//	arithmetic

Fixed	Fixed::operator+(const Fixed& obj) const {
	Fixed	res;
	res.setRawBits(this->getRawBits() + obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& obj) const {
	Fixed	res;
	res.setRawBits(this->getRawBits() - obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& obj) const {
	Fixed	res;
	res.setRawBits(long(this->getRawBits()) * long(obj.getRawBits()) >> bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed	res;
	res.setRawBits((long(this->getRawBits()) << bits) / long(obj.getRawBits()));
	return (res);
}

//	increment - decrement

Fixed&	Fixed::operator++(void) {
	(this->fix_point_value)++;
	return *this;	
}

Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	(this->fix_point_value)++;
	return temp;
}

Fixed&	Fixed::operator--(void) {
	(this->fix_point_value)--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	(this->fix_point_value)--;
	return temp;
}

//	min - max

Fixed&	Fixed::min(Fixed& obj1, Fixed& obj2) {
	if (obj1 <= obj2)
		return obj1;
	return obj2;
}

Fixed&	Fixed::max(Fixed& obj1, Fixed& obj2) {
	if (obj1 >= obj2)
		return obj1;
	return obj2;
}

const Fixed&	Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	if (obj1 <= obj2)
		return obj1;
	return obj2;
}

const Fixed&	Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	if (obj1 >= obj2)
		return obj1;
	return obj2;
}
