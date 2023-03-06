/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:49:02 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/20 15:04:09 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myException.hpp"

// myException::myException() {			only needed for inheritance
// 	return;
// }

myException::myException(const char* type) : type(type) {
	return;
}

const char*	myException::what() const throw() {
	return type;
}

myException::~myException() throw() {
	return;
}
