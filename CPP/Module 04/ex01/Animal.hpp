/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:00:06 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 16:03:41 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class	Animal {
	public:
		Animal();
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& obj);
		virtual	~Animal();

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual void	getBrain(void) const;
		virtual void	setIdea(std::string idea);

	protected:
		std::string	type;	
};

#endif
