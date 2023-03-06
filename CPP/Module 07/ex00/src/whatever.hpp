/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/26 14:08:56 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define RESET		"\033[0m"
# define GREY		"\033[0m\033[90m"
# define RED		"\033[0m\033[91m"
# define GREEN		"\033[0m\033[92m"
# define YELLOW		"\033[0m\033[93m"
# define BLUE		"\033[0m\033[94m"
# define MAGENTA	"\033[0m\033[95m"
# define CYAN		"\033[0m\033[96m"
# define WHITE		"\033[0m\033[97m"

# include <iostream>
# include <string>

template <typename T>
void	swap(T& a, T& b) {
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T&	min(T& a, T& b) {
	if (a > b)
		return b;
	return a;
}

template <typename T>
T&	max(T& a, T& b) {
	if (a < b)
		return b;
	return a;
}


#endif
