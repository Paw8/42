/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/11/01 17:11:20 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
# include <stack>

template <typename T, typename Basis = std::deque<T> >
class MutantStack : public std::stack<T, Basis> {
	public:
		MutantStack<T, Basis>();
		MutantStack<T, Basis>(const MutantStack<T, Basis>& obj);
		MutantStack<T, Basis>&	operator=(const MutantStack<T, Basis>& obj);
		~MutantStack<T, Basis>();
		MutantStack<T, Basis>(const Basis& obj);

		typedef	typename std::stack<T, Basis>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

template <typename T, typename Basis>
MutantStack<T, Basis>::MutantStack() : std::stack<T, Basis>() {
	return;
}

template <typename T, typename Basis>
MutantStack<T, Basis>::MutantStack(const Basis& obj) : std::stack<T, Basis>(obj) {
	return;
}

template <typename T, typename Basis>
MutantStack<T, Basis>::MutantStack(const MutantStack<T, Basis>& obj) : std::stack<T, Basis>(obj) {
	return;
}

template <typename T, typename Basis>
MutantStack<T, Basis>::~MutantStack() {
	return;
}

template <typename T, typename Basis>
MutantStack<T, Basis>&	MutantStack<T, Basis>::operator=(const MutantStack<T, Basis>& obj){
	if (this == &obj)
		return *this;
	this->~MutantStack();
	new (this)MutantStack(obj);
	return *this;
}

template <typename T, typename Basis>
typename MutantStack<T, Basis>::iterator	MutantStack<T, Basis>::begin(void) {
	return this->c.begin();		
}

template <typename T, typename Basis>
typename MutantStack<T, Basis>::iterator	MutantStack<T, Basis>::end(void) {
	return this->c.end();
}

#endif
