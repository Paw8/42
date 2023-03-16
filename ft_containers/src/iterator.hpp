/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:01:41 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/16 12:42:53 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "utils.hpp"
# include "iterator_traits.hpp"

namespace ft {

	template<typename T, typename vector>
	class iterator {
		public:
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;

			iterator() : m_ptr() {}
			iterator(pointer ptr) : m_ptr(ptr) {}
			
			template<typename Ptr>
			iterator(const iterator<Ptr, vector>& copy) : m_ptr(copy.base()) {}
			
			~iterator() {}

			iterator&	operator=(const iterator& other) {
				m_ptr = other.base();
				return *this;
			}

			reference	operator*(void) const { return *m_ptr; }

			pointer		operator->(void) const { return m_ptr; }

			reference	operator[](const difference_type& val) const { return *(m_ptr + val); }

			iterator&	operator++(void) {
				++m_ptr;
				return *this;
			}
			iterator	operator++(int) {
				iterator temp = *this;
				++m_ptr;
				return temp;
			}

			iterator&	operator--(void) {
				--m_ptr;
				return *this;
			}
			iterator	operator--(int) {
				iterator temp = *this;
				--m_ptr;
				return temp;
			}

			iterator	operator+(difference_type val) const { return iterator(m_ptr + val); }

			iterator	operator-(difference_type val) const { return iterator(m_ptr - val); }

			iterator&	operator+=(difference_type val) {
				m_ptr += val;
				return *this;
			}

			iterator&	operator-=(difference_type val) {
				m_ptr -= val;
				return *this;
			}

			const pointer&	base(void) const { return m_ptr; }

		private:
			pointer	m_ptr;
	};

	// end of class definition

	// non-member function overloads

	template<typename Ptr, typename vector>
	bool	operator==(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return static_cast<bool>(lhs.base() == rhs.base());
	}

	template<typename Ptr, typename vector>
	bool	operator!=(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return !(lhs == rhs);
	}

	template<typename Ptr, typename vector>
	bool	operator<(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return static_cast<bool>(lhs.base() < rhs.base());
	}

	template<typename Ptr, typename vector>
	bool	operator>(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return rhs < lhs;
	}

	template<typename Ptr, typename vector>
	bool	operator>=(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return !(lhs < rhs);
	}

	template<typename Ptr, typename vector>
	bool	operator<=(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return !(rhs < lhs);
	}

	template<typename Ptr, typename vector>
	typename iterator_traits<Ptr>::difference_type	operator-(const iterator<Ptr, vector>& lhs, const iterator<Ptr, vector>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template<typename Ptr, typename vector>
	iterator<Ptr, vector> operator+(typename iterator_traits<Ptr>::difference_type val, const iterator<Ptr, vector>& rhs) {
		return iterator<Ptr, vector>(rhs.base() + val);
	}

	// non-member function overloads CONST

	template<typename Ptr1, typename Ptr2, typename vector>
	bool	operator==(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return static_cast<bool>(lhs.base() == rhs.base());
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	bool operator!=(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return !(lhs == rhs);
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	bool	operator<(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return static_cast<bool>(lhs.base() < rhs.base());
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	bool	operator>(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return rhs < lhs;
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	bool	operator>=(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return !(lhs < rhs);
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	bool	operator<=(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return !(rhs < lhs);
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	typename iterator_traits<Ptr1>::difference_type	operator+(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return (lhs.base() + rhs.base());
	}

	template<typename Ptr1, typename Ptr2, typename vector>
	typename iterator_traits<Ptr1>::difference_type	operator-(const iterator<Ptr1, vector>& lhs, const iterator<Ptr2, vector>& rhs) {
		return (lhs.base() - rhs.base());
	}

}	// end of namespace
