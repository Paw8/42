/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:29:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/25 20:27:01 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	Base *base_array[10];
	for (int i = 0; i < 10; i++) {
		base_array[i] = generate();
		std::cout << "Pointer " << i << " of array is: ";
		identify(base_array[i]);
		std::cout << "Reference " << i << " of array is: ";
		identify(*base_array[i]);
		std::cout << std::endl;
		delete base_array[i];
	}
	return 0;
}