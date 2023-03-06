/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:21:39 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 13:09:29 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# define RESET			"\033[0m"
# define GREY			"\033[0m\033[90m"
# define RED			"\033[0m\033[91m"
# define GREEN			"\033[0m\033[92m"
# define YELLOW			"\033[0m\033[93m"
# define BLUE			"\033[0m\033[94m"
# define MAGENTA		"\033[0m\033[95m"
# define CYAN			"\033[0m\033[96m"
# define WHITE			"\033[0m\033[97m"

# include <iostream>
# include <string>

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& obj);
		virtual	~WrongAnimal();

		std::string	getType(void) const;
		void		makeSound(void) const;
	protected:
		std::string	type;	
};

#endif
