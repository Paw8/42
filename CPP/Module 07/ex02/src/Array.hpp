/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/26 17:33:38 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

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
class	Array {
	public:
		Array<T>();
		Array(unsigned int n);
		Array(const Array<T>& obj);
		Array<T>& operator=(const Array<T>& obj);
		~Array();

		T& operator[](unsigned int index) const;
		unsigned int	size(void) const;
		class OutOfBoundsException: public	std::exception {
			virtual const char*	what() const throw();
		};

	private:
		unsigned int	length;
		T*				arr;
};

# include "Array.tpp"

#endif
