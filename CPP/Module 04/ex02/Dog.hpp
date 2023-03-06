/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:52:09 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 18:03:47 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& obj);
		~Dog();

		void	makeSound(void) const;
		void	getBrain(void) const;
		void	setIdea(std::string idea);

	private:
		Brain*	ptr;
};

#endif
