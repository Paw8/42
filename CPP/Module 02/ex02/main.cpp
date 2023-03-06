/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:02:15 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/10 12:57:19 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
  
int	main() {
	Fixed a;
	Fixed b(83.57825f);
	Fixed c(42.42f);
	Fixed const d_c(b);
	Fixed const e_c(8);
	Fixed const f_c(21);
	a = Fixed(-2.f);
	
	std::cout << "<<<< Comparison >>>>" << std::endl << std::endl;
	if (e_c < d_c)
		std::cout << e_c << " is smaller then " << d_c << std::endl;
	if (b <= c)
		std::cout << b << " is smaller or equal to " << c << std::endl;
	if (b > c)
		std::cout << b << " is bigger then " << c << std::endl;
	if (b >= c)
		std::cout << b << " is bigger or equal to " << c << std::endl;
	if (b == c)
		std::cout << b << " is equal to " << c << std::endl;
	if (b != c)
		std::cout << b << " is not equal to " << c << std::endl;	
	std::cout << std::endl << "<<<< Arithmetik >>>>" << std::endl << std::endl; 
	a = a + e_c;
	std::cout << a << std::endl;
	a = a - e_c + a + e_c;
	std::cout << a << std::endl;
	a = a * e_c;
	std::cout << a << std::endl;
	a = b / e_c;
	std::cout << std::setprecision(4) << a << std::endl;
	std::cout << std::endl << "<<<< Increment / Decrement >>>>" << std::endl << std::endl;
	a = Fixed();
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	a++;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	++a;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	--a;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	a--;
	std::cout << a << std::endl;
	
	a = Fixed(2);
	std::cout << b << std::endl;
	b = ++a;
	std::cout << b << std::endl;
	std::cout << std::endl << "<<<< min / max >>>>" << std::endl << std::endl;
	
	std::cout << "c: " << c << "\te_c: " << e_c << "  \tf_c: " << f_c << " \tb: " << b << std::endl;
	std::cout << "Calling by class: " << Fixed::min(c, e_c) << " is smaller then " << Fixed::max(c, e_c) << std::endl;
	std::cout << "calling with object: " << f_c.min(c, e_c) << " is smaller then " << f_c.max(c, e_c) << std::endl;
	std::cout << "Assigning with object to c: " << c << std::endl;
	c = c.min(f_c, e_c);
	std::cout << "c is now: " << c << std::endl;
	std::cout << "Assigning with class to c: " << c << std::endl;
	c = Fixed::min(e_c, b);
	std::cout << "c is now: " << c << std::endl;
	
	return 0;
}
