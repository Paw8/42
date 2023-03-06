/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:44:12 by mokatova          #+#    #+#             */
/*   Updated: 2022/06/15 22:44:30 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	*line;

	i = 0;
	rd = 0;
	line = malloc(100000);
	while (1)
	{
		rd = read(fd, &line[i], 1);
		if (rd <= 0 || line[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	return (line);
}
