/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:02:41 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/10 12:34:08 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>

class	Fixed {
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//	comparison
		
		bool	operator>(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;
		
		//	arithmetic
		
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;

		//	increment - decrement

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		//	min - max
		
		static Fixed&		min(Fixed& obj1, Fixed& obj2);
		static Fixed&		max(Fixed& obj1, Fixed& obj2);
		const static Fixed&	min(const Fixed& obj1, const Fixed& obj2);
		const static Fixed&	max(const Fixed& obj1, const Fixed& obj2);
		
	private:
		int					fix_point_value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif
