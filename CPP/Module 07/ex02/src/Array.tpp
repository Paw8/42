/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:18 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/26 18:17:15 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Array.hpp"

template <typename T>
Array<T>::Array() {
	length = 0;
	arr = 0;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	length = n;
	if (!length)
		arr = 0;
	else
		arr = new T[n];
	return;
}

template <typename T>
Array<T>::Array(const Array<T>& obj) : length(obj.length), arr(obj.arr) {
	unsigned int	index = 0;
	if (!length)
		arr = 0;
	else {
		arr = new T[length];
		while (index < length) {
			arr[index] = obj.arr[index];
			index++;
		}
	}
	return;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& obj) {
	unsigned int	index = 0;
	if (this == &obj)
		return *this;
	if (length)
		delete []arr;
	length = obj.length;
	if (!length)
		arr = 0;
	else {
		arr = new T[length];
		while (index < length) {
			arr[index] = obj.arr[index];
			index++;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (length)
		delete []arr;
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return length;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) const {
	if (length <= index)
		throw OutOfBoundsException();
	return arr[index];
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index out of bounds!");
}
