/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:59:51 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/16 17:36:43 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "utils.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"

namespace	ft {

	template <typename T, typename Alloc = std::allocator<T> >
	class	vector {
		public:
			typedef Alloc											allocator_type;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::value_type				value_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef ft::iterator<pointer, vector<T, Alloc> >		iterator;
			typedef ft::iterator<const_pointer, vector<T, Alloc> >	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			explicit vector(const allocator_type& alloc = allocator_type()) : m_allocator(alloc), m_size(0), m_capacity(0) {};

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_allocator(alloc), m_array(m_allocator.allocate(n)), m_size(n), m_capacity(n) {
				for(size_type i = 0; i < n; i++)
					m_allocator.construct(&m_array[i], val);
			}

			template <typename InputIterator>
			vector(InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : m_allocator(alloc), m_size(0) {
				while (last-- != first)
					m_size++;
				m_capacity = m_size;
				m_array = m_allocator.allocate(m_capacity);
				for (size_type i = 0; i < m_size; ++i)
					m_array[i] = *first++;
			}

			vector(const vector& other) : m_allocator(other.m_allocator), m_array(m_allocator.allocate(other.m_capacity)), m_size(other.m_size), m_capacity(other.m_capacity) {
				for (size_type i = 0; i < m_size; ++i)
					m_allocator.construct(&m_array[i], other.m_array[i]);
			}

			vector&	operator=(const vector& other) {
				if (this != &other) {
					m_allocator = other.m_allocator;
					m_array = m_allocator.allocate(other.m_capacity);
					m_size = other.m_size;
					m_capacity = other.m_capacity;
					for (size_type i = 0; i < m_size; ++i)
						m_allocator.construct(&m_array[i], other.m_array[i]);
				}
				return *this;
			}

			~vector() {
				if (m_capacity) {
					for (size_type i = 0; i < m_size; ++i) {
						m_allocator.destroy(&m_array[i]);
					}
					m_allocator.deallocate(m_array, m_capacity);
				}
				return;
			}

			//	iterator

			iterator				begin(void) { return iterator(m_array); }
			const_iterator			begin(void) const { return const_iterator(m_array); }
			iterator				end(void) { return iterator(m_array + m_size); }
			const_iterator			end(void) const { return const_iterator(m_array + m_size); }
			reverse_iterator		rbegin(void) { return reverse_iterator(this->end()); }
			const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(this->end()); }
			reverse_iterator		rend(void) { return reverse_iterator(this->begin()); }
			const_reverse_iterator	rend(void) const { return const_reverse_iterator(this->begin()); }

			//	capacity

			size_type	size(void) const { return m_size; }

			size_type	max_size(void) const { return m_allocator.max_size(); }

			void		resize(size_type size, value_type value = value_type()) {
				if (size <= m_capacity) {
					if (size <= m_size) {
						for (size_type i = size; i < m_size; ++i)
							m_allocator.destroy(&m_array[i]);
					}
					else { 
						while (m_size < size)
							m_array[m_size++] = value;
					}
				}
				else {
					pointer	temp = m_allocator.allocate(size);
					for (size_type i = 0; i < m_size; i++) {
						m_allocator.construct(&temp[i], m_array[i]);
						m_allocator.destroy(&m_array[i]);
					}
					while (m_size < size)
						temp[m_size++] = value;
					m_allocator.deallocate(m_array, m_capacity);
					m_array = temp;
					m_capacity = size;
				}
				m_size = size;
			}

			size_type	capacity(void) const { return m_capacity; }

			bool		empty(void) const { return static_cast<bool>(!m_size); }

			void		reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error("ft::vector");
				if (m_capacity < n)
					re_alloc(n);
			}

			//	element access

			reference		operator[](size_type n) { return m_array[n]; }
			const_reference	operator[](size_type n) const { return m_array[n]; }

			reference		at(size_type n) {
				if (!m_array || n >= m_size)
					throw std::out_of_range("ft::vector");
				return m_array[n];
			}
			const_reference	at(size_type n) const {
				if (!m_array || n >= m_size)
					throw std::out_of_range("ft::vector");
				return m_array[n];
			}

			reference		front(void) { return m_array[0]; }
			const_reference	front(void) const { return m_array[0]; }

			reference		back(void) { return m_array[m_size - 1]; }
			const_reference	back(void) const { return m_array[m_size - 1]; }

			pointer			data(void) { return m_array; }
			const_pointer	data(void) const { return m_array; }

			//	modifiers

			template <typename InputIterator>
			void	assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
				InputIterator	temp1 = first;
				InputIterator	temp2 = last;
				size_type comp = 0;
				while (temp1++ != temp2)
					++comp;
				if (comp > m_capacity) {
					this->~vector();
					*this = vector(first, last);
				}
				else {
					this->clear();
					m_size = comp;
					size_type	i = 0;
					while (first != last) {
						m_allocator.construct(&m_array[i], *first);
						++first;
						++i;
					}
				}
			}	
			void	assign(size_type n, const value_type& val) {
				if (n > m_capacity) {
					this->~vector();
					*this = vector(n, val);
				}
				else {
					this->clear();
					m_size = n;
					for (size_type i = 0; i < n; ++i)
						m_allocator.construct(&m_array[i], val);
				}
			}

			void	push_back(const_reference element) {
				if (!m_capacity) {
					m_capacity = 1;
					m_array = m_allocator.allocate(m_capacity);
				}
				else if (m_size == m_capacity)
					re_alloc(m_capacity * 2);
				m_array[m_size] = element;
				m_size++;
			}

			void	pop_back(void) {
				if (m_size) {
					m_size--;
					m_allocator.destroy(&m_array[m_size]);
				}
			}

			iterator	insert(iterator position, const value_type& val) {	// protect against out of bounds?
				difference_type	index = position - this->begin();
				if (!m_size)
					re_alloc(1);	
				else if (m_size == m_capacity)
					re_alloc(m_capacity * 2);
				iterator ret = this->begin() + index;
				iterator it = this->end();
				++m_size;
				while(it-- != ret) {
					m_allocator.construct(&(*(it + 1)), *it);
					m_allocator.destroy(&(*it));
				}
				m_allocator.construct(&(*(it + 1)), val);
				return ret;
			}
			void	insert(iterator position, size_type n, const value_type& val) {
				if (position >= this->begin() && position <= this->end()) {
					difference_type index = position - this->begin();
					if (m_size + n > m_capacity) {
						re_alloc(m_size + n);
					}
					iterator ret = this->begin() + index;
					iterator it = this->end() - 1;
					m_size += n;
					while (n--) {
						while (it >= ret) {
							m_allocator.construct(&(*(it + n + 1)), *it);
							m_allocator.destroy(&(*it));
							--it;
						}
						m_allocator.construct(&(*(it + n + 1)), val);
					}
				}
			}
			template <typename InputIterator>
			void		insert(iterator position, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
				if (position >= this->begin() && position <= this->end()) {
					difference_type index = position - this->begin();
					InputIterator	temp1 = first;
					InputIterator	temp2 = last;
					size_type dist = 0;
					while (temp1++ != temp2)
						++dist;
					if (m_size + dist > m_capacity) {
						re_alloc(m_size + dist);
					}
					iterator ret = this->begin() + index;
					iterator it = this->end() - 1;
					m_size += dist;
					while (first != last) {
						while (it >= ret) {
							m_allocator.construct(&(*(it + dist)), *it);
							m_allocator.destroy(&(*it));
							--it;
						}
						m_allocator.construct(&(*(ret)), *first);
						++ret;
						++first;
					}
				}
			}

			iterator	erase(iterator position) {
				if (position < this->end()) {
					iterator ret = position;
					while (++position != this->end()) {
						m_allocator.destroy(&(*(position - 1)));
						m_allocator.construct(&(*(position - 1)), *position);
					}
					m_allocator.destroy(&(*(position - 1)));
					--m_size;
					return ret;
				}
				return position;
			}
			iterator	erase(iterator first, iterator last) {
				if (first == last)
					return last;
				else if (first < last) {
					iterator ret = first;
					difference_type	dist = last - first;
					while (first != this->end()) {
						m_allocator.destroy(&(*first));
						if (last != this->end()) {
							m_allocator.construct(&(*first), *last);
							++last;
						}
						++first;
					}
					m_size -= dist;
					return ret;
				}
				return first;
			}

			void	swap(vector& other) {
				if (this != &other) {
					std::swap(m_size, other.m_size);
					std::swap(m_capacity, other.m_capacity);
					std::swap(m_array, other.m_array);
					std::swap(m_allocator, other.m_allocator);
				}
			}

			void		clear(void) {
				if (m_size) {
					for (size_type i = 0; i < m_size; ++i)
						m_allocator.destroy(&m_array[i]);
					m_size = 0;
				}
			}

			//	allocator

			allocator_type	get_allocator(void) const { return m_allocator; }

		private:
			allocator_type	m_allocator;
			pointer			m_array;
			size_type		m_size;
			size_type		m_capacity;

			void	re_alloc(size_type n) {
				pointer temp = m_allocator.allocate(n);
				for (size_type i = 0; i < m_size; ++i) {
					m_allocator.construct(&temp[i], m_array[i]);
					m_allocator.destroy(&m_array[i]);
				}
				if (m_capacity)
					m_allocator.deallocate(m_array, m_capacity);
				m_capacity = n;
				m_array = temp;
			}
	};

	//	end of class definition

	//	non-member function overloads

	template <typename T, typename Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename T, typename Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <typename T, typename Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T, typename Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template <typename T, typename Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <typename T, typename Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <typename T, typename Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
	
}	// end of namespace definition
