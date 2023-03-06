/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:17:42 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 20:33:22 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

void	convert(std::string arg) {
	e_type	type(UNDEF);
	gettype(arg, &type);
	switch (type) {
		case NaN:
			output_nan(arg);
			break;
		case INF:
			output_inf(arg);
			break;
		case CHAR:
			output_char(arg);
			break;
		case INT:
			output_int(arg);
			break;
		case FLOAT:
			output_float(arg);
			break;
		case DOUBLE:
			output_double(arg);
			break;
		default:
			std::cout << "'Converter' doesn't support: " << RED << arg << RESET << std::endl;
	}
}

void	gettype(std::string arg, e_type* type) {
	if (std::isprint(arg.at(0)) && !std::isdigit((arg.at(0))) && arg.length() == 1)
		*type = CHAR;
	else if (arg == "nan" || arg == "nanf")
		*type = NaN;
	else if (arg == "+inf" || arg == "-inf" || arg == "+inff" || arg == "-inff")
		*type = INF;
	else
		check_rest(arg, type);
}

void	check_rest(std::string arg, e_type* type) {
	std::string::iterator	index(arg.begin());
	std::string::iterator	end(arg.end());
	bool	point(false);
	
	if (*index == '+' || *index == '-')
		index++;
	if (!std::isdigit(*index))
		return;
	while (index != end) {
		while (std::isdigit(*index))
			index++;
		if (index == end) {
			if (point)
				*type = DOUBLE;
			else
				*type = INT;
		} 
		else if (*index == '.') {
			if (!point && std::isdigit(*(++index)))
				point = true;
			else
				return;
		}
		else if (*index == 'f' && ++index == end) 
			*type = FLOAT;
		else
			return;		
	}
}

void	output_nan(std::string arg) {
	std::cout << "char: out of bounds" << std::endl;
	std::cout << "int: out of bounds" << std::endl;
	if (arg == "nan") {
		double nbr = std::numeric_limits<double>::quiet_NaN();
    	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
    	std::cout << "double: " << nbr << std::endl;
	}
	else {
		float nbr = std::numeric_limits<float>::quiet_NaN();
    	std::cout << "float: " << nbr << "f" << std::endl;
    	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
}

void	output_inf(std::string arg) {
	int	sign = 1;
	if (arg.at(0) == '-')
		sign = -1;
	std::cout << "char: out of bounds" << std::endl;
	std::cout << "int: out of bounds" << std::endl;
	if (arg == "+inf" || arg == "-inf") {
		double nbr = std::numeric_limits<double>::infinity();
		std::cout << "float: " << sign * static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << sign * nbr << std::endl;
	}
	else {
		float nbr = std::numeric_limits<double>::infinity();
		std::cout << "float: " << sign * nbr << "f" << std::endl;
		std::cout << "double: " << sign * static_cast<double>(nbr) << std::endl;
	}
}

void	output_char(std::string arg) {
	char c = static_cast<char>(arg.at(0));
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	output_int(std::string arg) {
	int	nbr = atoi(arg.c_str());
	if (nbr != strtol(arg.c_str(), 0, 10)) {
		std::cout << RED << "Error: " << RESET << "INT out of bounds!" << std::endl;
	}
	else {
		if (0 <= nbr && nbr < 128) {
			if (std::isprint(nbr))
				std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else	
			std::cout << "char: out of bounds" << std::endl;
		std::cout << "int: " << nbr << std::endl;
		std::cout << "float: " << static_cast<float>(nbr);
		if (nbr < 1000000)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr);
		if (nbr < 1000000)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
}

void	output_float(std::string arg) {
	float	nbr = strtof(arg.c_str(), 0);
	
	if (0 <= nbr && nbr < 128) {
		if (std::isprint(nbr))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else	
		std::cout << "char: out of bounds" << std::endl;
	
	if (nbr < -2147483648 || 2147483647 < nbr)
		std::cout << "int: out of bounds" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;

	double tmp;
	std::cout << "float: " << nbr;
	if (std::modf(nbr, &tmp) == 0 && nbr < 999999.5)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(nbr);
	if (std::modf(nbr, &tmp) == 0 && nbr < 999999.5)
		std::cout << ".0";
	std::cout << std::endl;
}

void	output_double(std::string arg) {
	double nbr = strtod(arg.c_str(), NULL);
	
	if (0 <= nbr && nbr < 128) {
		if (std::isprint(nbr))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else	
		std::cout << "char: out of bounds" << std::endl;

	if (nbr < -2147483648 || 2147483647 < nbr)
		std::cout << "int: out of bounds" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;

	double tmp;
	std::cout << "float: " << static_cast<float>(nbr);
	if (std::modf(nbr, &tmp) == 0 && nbr < 999999.5)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << nbr;
	if (std::modf(nbr, &tmp) == 0 && nbr < 999999.5)
		std::cout << ".0";
	std::cout << std::endl;
}
