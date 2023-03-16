/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:00:01 by pcordeir          #+#    #+#             */
/*   Updated: 2023/02/16 13:37:49 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	template <typename T1, typename T2>
	struct pair {
		// public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			pair() : first(), second() {}

			template<typename U, typename V>
			pair (const pair<U, V>& other) : first(other.first), second(other.second) {}

			pair (const first_type& a, const second_type& b) : first(a), second(b) {}

			pair& operator=(const pair& other) {
				this->~pair();
    			new (this)pair(other.first, other.second);
    			return *this;
			}
	};

	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 a, T2 b) {
		return (pair<T1, T2>(a, b));
	}

	template<typename T1, typename T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		 return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template<typename T1, typename T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template<typename T1, typename T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second);		// why not lhs.first == rhs.first
	}

	template<typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template<typename T1, typename T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return rhs < lhs;
	}

	template<typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}

}
