/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:25:33 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/09 22:19:18 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//----------------------	COLORS				----------------------

# define RESET		"\033[0m"
# define GREY		"\033[0m\033[90m"
# define C_RED		"\033[0m\033[91m"
# define GREEN		"\033[0m\033[92m"
# define YELLOW		"\033[0m\033[93m"
# define BLUE		"\033[0m\033[94m"
# define MAGENTA	"\033[0m\033[95m"
# define CYAN		"\033[0m\033[96m"
# define WHITE		"\033[0m\033[97m"

//----------------------	STD::HEADERS		----------------------

# include <iostream>
# include <string>
# include <memory>
# include <exception>
# include <cstddef>
# include <functional>
# include <typeinfo>

//----------------------	FT_NAMESPACE		----------------------

namespace ft {
	
//----------------------	ENABLE_IF			----------------------

	template <bool, typename T = void >
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

//----------------------	INTEGRAL_CONSTANT	----------------------

	template<typename T, T v>
	struct integral_constant {
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		operator value_type() { return v; }
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

//----------------------	IS_INTEGRAL			----------------------

	template<typename> struct	is_integral								:public false_type {};
	template<> struct 			is_integral<bool>						:public true_type {};
	template<> struct 			is_integral<char>						:public true_type {};
	template<> struct 			is_integral<wchar_t>					:public true_type {};
	template<> struct 			is_integral<signed char>				:public true_type {};
	template<> struct 			is_integral<short int>					:public true_type {};
	template<> struct 			is_integral<int>						:public true_type {};
	template<> struct 			is_integral<long int>					:public true_type {};
	template<> struct 			is_integral<long long int>				:public true_type {};
	template<> struct 			is_integral<unsigned char>				:public true_type {};
	template<> struct 			is_integral<unsigned short int>			:public true_type {};
	template<> struct 			is_integral<unsigned int>				:public true_type {};
	template<> struct 			is_integral<unsigned long int>			:public true_type {};
	template<> struct 			is_integral<unsigned long long int>		:public true_type {};

//----------------------	EQUAL				----------------------

	template <class Input1, class Input2>
	bool	equal(Input1 first1, Input1 last1, Input2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class Input1, class Input2, class BinaryPredicate>
	bool	equal(Input1 first1, Input1 last1, Input2 first2, BinaryPredicate p) {
		while (first1 != last1) {
			if (!p(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

//----------------------	LEXICOGRAPHICAL		----------------------

	template <class Input1, class Input2>
	bool	lexicographical_compare(Input1 first1, Input1 last1, Input2 first2, Input2 last2) {
		while ((first1 != last1) && (first2 != last2)) {
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template <class Input1, class Input2, class Compare>
	bool	lexicographical_compare(Input1 first1, Input1 last1, Input2 first2, Input2 last2, Compare comp) {
		while ((first1 != last1) && (first2 != last2)) {
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
			++first1;
			++first2;
		}
		return ((first1 == last1) && (first2 != last2));
	}

}

//----------------------	END FT_NAMESPACE	----------------------
