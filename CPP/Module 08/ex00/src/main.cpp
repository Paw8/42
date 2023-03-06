/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/27 12:34:00 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	{
		std::cout << std::endl << YELLOW << "<<<< Testing with std::vector >>>>" << RESET << std::endl;
		std::vector<int>			vec;
		std::vector<int>::iterator	vec_it;

		vec.push_back(10);
		vec.push_back(-4);
		vec.push_back(7);
		vec_it = easyfind(vec, -4);
		if (vec_it != vec.end())
			std::cout << *vec_it << std::endl;
		vec_it = easyfind(vec, 22);
		if (vec_it != vec.end())
			std::cout << *vec_it << std::endl;
	}
	{
		std::cout << std::endl << YELLOW << "<<<< Testing with std::list >>>>" << RESET << std::endl;
		std::list<int>				list;
		std::list<int>::iterator	list_it;

		list.push_back(2);
		list.push_back(6);
		list.push_back(-4);
		list.push_back(4);
		list_it = easyfind(list, -4);
		if (list_it != list.end())
			std::cout << *list_it << std::endl;
		list_it = easyfind(list, 22);
		if (list_it != list.end())
			std::cout << *list_it << std::endl;
	}
	{
		std::cout << std::endl << YELLOW << "<<<< Testing with std::deq >>>>" << RESET << std::endl;
		std::deque<int>				deq;
		std::deque<int>::iterator	deq_it;

		deq.push_back(5);
		deq.push_back(18);
		deq.push_back(22);
		deq.push_back(1500);
		deq.push_back(53974);
		deq_it = easyfind(deq, -4);
		if (deq_it != deq.end())
			std::cout << *deq_it << std::endl;
		deq_it = easyfind(deq, 22);
		if (deq_it != deq.end())
			std::cout << *deq_it << std::endl;
	}
	std::cout << std::endl;
    return 0;
}
