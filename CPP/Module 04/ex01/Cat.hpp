/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:14:54 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/17 14:49:37 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& obj);
		~Cat();

		void	makeSound(void) const;
		void	getBrain(void) const;
		void	setIdea(std::string idea);

	private:
		Brain*	ptr;
};

#endif
