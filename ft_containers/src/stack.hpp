/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:42:50 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/21 18:20:51 by pcordeir         ###   ########.fr       */
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


		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

		~stack() {}

		bool					empty(void) const { return (c.size() == 0); }

		size_type				size(void) const { return (c.size()); }

		value_type&				top(void) { return (c.back()); }

		const value_type&		top(void) const { return (c.back()); }

		void					push(const value_type& val) { c.push_back(val); }

		void					pop(void) { c.pop_back(); }

		const container_type	base(void) const { return c; }

		private:
			container_type	c;

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
