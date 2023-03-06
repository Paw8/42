/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:46:22 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/19 20:28:16 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	width;
	int	length;

	if (argc == 2)
	{	
		length = checkfile(argv[1], &width);
		fdf(argv[1], length, width);
	}
	return (0);
}
