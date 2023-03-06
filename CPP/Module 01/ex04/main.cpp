/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:04:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/10/05 11:11:14 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>																

int	main(int argc, char** argv) {
	
	if (argc == 4) {
		std::string find = argv[2];
		std::string rep = argv[3];
		if (find != rep) {
			std::string	buf;
			std::string file = argv[1];
			std::fstream input;
			
			input.open(file.c_str());
			if (input.fail())
				std::cout << "No such file" << std::endl;
			else if (input.is_open()) {
				file.append(".replace");
				std::ofstream output(file.c_str());
				while (std::getline(input, buf)) {
					int	i = buf.find(find);
					while (i != -1) {
						buf.erase(i, find.length());
						buf.insert(i, rep, 0, rep.length());
						i = buf.find(find);
					}
					output << buf << std::endl;
				}
				input.close();
				output.close();
			}
		}
		else
			std::cout << "Nothing to replace!" << std::endl;
	}
	else
		std::cout << "Please enter 3 Arguments!" << std::endl;
	return 0;	
}