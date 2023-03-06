/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/26 12:37:21 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Awesome {
	public:
		Awesome( int n ) : _n( n ) {}
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) {
	o << rhs.get();
	return o;
}


int main(void) {
	{
		int a = 2;
		int b = 3;
		std::cout << std::endl << GREEN << "<<<< Testing with Int >>>>" << std::endl;
		std::cout << "Befor Swap: " << RESET;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << GREEN << "After Swap: " << RESET;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
		std::cout << "max(a, a) = " << max(a, a) << std::endl;
		std::cout << "min(a, a) = " << min(a, a) << std::endl << std::endl;
		
		std::cout << GREEN << "<<<< Testing with String >>>>" << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Befor Swap: " << RESET;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		swap(c, d);
		std::cout << GREEN << "After Swap: " << RESET;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << min(c, d) << std::endl;
		std::cout << "max(c, d) = " << max(c, d) << std::endl;
		std::cout << "max(c, c) = " << max(c, c) << std::endl;
		std::cout << "min(c, c) = " << min(c, c) << std::endl << std::endl;;
	}
	{
		Awesome a(2), b(4);
		std::cout << GREEN << "<<<< Testing with the Awesome Class >>>>" << std::endl;
		std::cout << "Befor Swap: " << RESET;
		std::cout << "a: " << a << " , b: " << b << std::endl;
		swap(a, b);
		std::cout << GREEN << "After Swap: " << RESET;
		std::cout << "a: " << a << " , b: " << b << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, a) = " << max(a, a) << std::endl;
		std::cout << "min(a, a) = " << min(a, a) << std::endl;
	}
	return 0;
}