/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:23:21 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/08 13:35:02 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "utils.hpp"
# include "iterator_traits.hpp"

namespace ft {

	template<typename T>
	class reverse_iterator {
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

			reverse_iterator() : r_iter() {}
			explicit reverse_iterator(iterator_type iter) : r_iter(iter) {}

			template <typename Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : r_iter(rev_it.base()) {}
			~reverse_iterator() {}

			reverse_iterator&	operator=(const reverse_iterator& other) {
				if (this != &other)
					r_iter = other.r_iter;
				return *this;
			}

			reference	operator*(void) const {
				return (--iterator_type(r_iter)).operator*();
			}

			pointer		operator->(void) const {
				return &(operator*());
			}

			reference			operator[](difference_type val) const { return *(*this + val); }

			reverse_iterator&	operator++(void) {
				--r_iter;
				return *this;
			}
			reverse_iterator	operator++(int) {
				reverse_iterator temp = *this;
				--r_iter;
				return temp;
			}

			reverse_iterator&	operator--(void) {
				++r_iter;
				return *this;
			}
			reverse_iterator	operator--(int) {
				reverse_iterator temp = *this;
				++r_iter;
				return temp;
			}

			reverse_iterator	operator+(difference_type val) const { return reverse_iterator(r_iter - val); }

			reverse_iterator	operator-(difference_type val) const { return reverse_iterator(r_iter + val); }

			reverse_iterator&	operator+=(int val) {
				r_iter -= val;
				return *this;
			}

			reverse_iterator&	operator-=(int val) {
				r_iter += val;
				return *this;
			}

			const iterator_type	base(void) const { return r_iter; }

		private:
			iterator_type	r_iter;
	};

	// end of class definition

	// non-member function overloads

	template <typename T>
	bool	operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return static_cast<bool>(lhs.base() == rhs.base());
	}

	template <typename T>
	bool	operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template <typename T>
	bool	operator<(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return static_cast<bool>(rhs.base() < lhs.base());
	}

	template <typename T>
	bool	operator>(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <typename T>
	bool	operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return !(rhs.base() < lhs.base());
	}

	template <typename T>
	bool	operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return !(lhs.base() < rhs.base());
	}

	template<typename T>
	typename iterator_traits<T>::difference_type	operator+(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	typename iterator_traits<T>::difference_type	operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (rhs.base() - lhs.base());
	}

	// non-member function overloads CONST

	template <typename T1, typename T2>
	bool	operator==(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return static_cast<bool>(lhs.base() == rhs.base());
	}

	template <typename T1, typename T2>
	bool	operator!=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template <typename T1, typename T2>
	bool	operator<(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return static_cast<bool>(rhs.base() < lhs.base());
	}

	template <typename T1, typename T2>
	bool	operator>(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <typename T1, typename T2>
	bool	operator>=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return !(rhs.base() < lhs.base());
	}

	template <typename T1, typename T2>
	bool	operator<=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return !(lhs.base() < rhs.base());
	}

	template <typename T1, typename T2>
	typename iterator_traits<T1>::difference_type	operator-(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return (rhs.base() - lhs.base());
	}

	template<typename iter>
	reverse_iterator<iter> operator+(typename iterator_traits<iter>::difference_type val, const reverse_iterator<iter>& rhs) {
		return reverse_iterator<iter>(rhs.base() - val);
	}
	
}	// end of namespace
