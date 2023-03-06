/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:18:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/23 22:11:54 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void) {
	Form*	rrf;
	Intern	someRandomIntern;
	
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "42");
	if (rrf)
		std::cout << *rrf;
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Loki");
	if (rrf)
		std::cout << *rrf;
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Thor");
	if (rrf)
		std::cout << *rrf;
	std::cout << std::endl;
	return 0;
}