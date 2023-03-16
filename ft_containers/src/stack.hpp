/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:42:50 by pcordeir          #+#    #+#             */
/*   Updated: 2023/01/18 14:57:23 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "vector.hpp"

namespace ft {
	
	template <typename T, typename Container = ft::vector<T> >
	class stack {
		public:
			typedef	Container								container_type;
			typedef	typename container_type::value_type		value_type;
			typedef	typename container_type::size_type		size_type;


		explicit stack (const container_type& ctnr = container_type()) : s_container(ctnr) {}

		~stack() {}

		bool					empty(void) const { return (s_container.size() == 0); }

		size_type				size(void) const { return (s_container.size()); }

		value_type&				top(void) { return (s_container.back()); }

		const value_type&		top(void) const { return (s_container.back()); }

		void					push(const value_type& val) { s_container.push_back(val); }

		void					pop(void) { s_container.pop_back(); }

		const container_type	base(void) const { return s_container; }

		private:
			container_type	s_container;

	};

	// end of class definition

	template <typename T, typename Container>
	bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return static_cast<bool>(lhs.base() == rhs.base());
	}

	template <typename T, typename Container>
	bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template <typename T, typename Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return static_cast<bool>(lhs.base() < rhs.base());
	}

	template <typename T, typename Container>
	bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return rhs.base() < lhs.base();
	}

	template <typename T, typename Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(rhs.base() < lhs.base());
	}

	template <typename T, typename Container>
	bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs.base() < rhs.base());
	}

}	// end of namespace
