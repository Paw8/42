/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:53:21 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 12:50:10 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# define RESET		"\033[0m"
# define GREY		"\033[0m\033[90m"
# define RED		"\033[0m\033[91m"
# define GREEN		"\033[0m\033[92m"
# define YELLOW		"\033[0m\033[93m"
# define BLUE		"\033[0m\033[94m"
# define MAGENTA	"\033[0m\033[95m"
# define CYAN		"\033[0m\033[96m"
# define WHITE		"\033[0m\033[97m"

# include <iostream>
# include <string>
# include <limits>
# include <cmath>

enum e_type {
	UNDEF,
	NaN,
	INF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

void	convert(std::string arg);
void	gettype(std::string arg, e_type* type);
void	check_rest(std::string arg, e_type* type);
void	output_nan(std::string arg);
void	output_inf(std::string arg);
void	output_char(std::string arg);
void	output_int(std::string arg);
void	output_float(std::string arg);
void	output_double(std::string arg);

#endif
