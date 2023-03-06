/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:46:38 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 01:02:17 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_EXCEPTION_HPP
# define MY_EXCEPTION_HPP

#include <iostream>

class	myException : public	std::exception {
	public:
		// myException();	only needed for inheritance
		myException(const char* type);
		virtual	~myException() throw ();

		const char* what() const throw ();

	private:
		const char*	type;
};

#endif
