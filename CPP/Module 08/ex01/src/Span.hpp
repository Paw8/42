/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/27 20:27:58 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

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
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <deque>
# include <cstdlib>

class	Span {
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		Span&	operator=(const Span& obj);
		~Span();
		
		void			addNumber(int nbr);
		void			addRNG(int amount);
		unsigned int	getSize(void) const;
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void) const;
		void			print(void);
		class	OutOfBounds: public std::exception {
			const char*	what() const throw();
		};
		class	NotEnoughElements: public std::exception {
			const char*	what() const throw();
		};
	private:
		unsigned int		size;
		std::vector<int>	vec;	
};

#endif
