/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:36:44 by pcordeir          #+#    #+#             */
/*   Updated: 2021/12/23 17:37:56 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	int			i;
	int			byte;

	if (fd >= 0 && fd < 4096 && BUFFER_SIZE > 0)
	{
		if (!line)
			startnewline(&line, fd);
		if (!line)
			return (NULL);
		i = 0;
		byte = 1;
		while (byte)
		{
			while (*(line + i) != '\n' && *(line + i))
				i++;
			if (*(line + i) == '\n')
				return (splitline(&line, (i + 1)));
			else
				addnewline(&line, &byte, fd);
		}
		return (endoffile(&line));
	}
	return (NULL);
}

void	startnewline(char **s, int fd)
{
	char	*temp;
	int		byte;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = read(fd, temp, BUFFER_SIZE);
	if (byte <= 0)
		free(temp);
	else
	{
		*(temp + byte) = '\0';
		*s = ft_strcpy(malloc(sizeof(char) * (byte + 1)), temp);
		free(temp);
	}
}

char	*splitline(char **s, int size)
{
	char	*ret;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (size + 1));
	temp = malloc(sizeof(char) * (ft_strlen(*s) - size + 1));
	while (size--)
	{
		*(ret + i) = *(*s + i);
		i++;
	}
	*(ret + i) = '\0';
	while (*(*s + i))
	{
		temp[j++] = *(*s + i);
		i++;
	}
	temp[j] = '\0';
	free(*s);
	*s = ft_strcpy(malloc(sizeof(char) * (j + 1)), temp);
	free(temp);
	return (ret);
}

void	addnewline(char **s, int *byte, int fd)
{
	char	*temp;
	int		i;
	int		size;

	size = ft_strlen(*s);
	temp = malloc(sizeof(char) * (size + BUFFER_SIZE + 1));
	*byte = read(fd, temp + size, BUFFER_SIZE);
	*(temp + size + *byte) = '\0';
	i = 0;
	while (*(*s + i))
	{
		*(temp + i) = *(*s + i);
		i++;
	}
	free(*s);
	*s = ft_strcpy(malloc(sizeof(char) * (ft_strlen(temp) + 1)), temp);
	free(temp);
}

char	*endoffile(char **s)
{
	char	*ret;

	if (!(**s))
	{
		free(*s);
		*s = 0;
		return (NULL);
	}
	else
	{
		ret = ft_strcpy(malloc(sizeof(char) * (ft_strlen(*s) + 1)), *s);
		free(*s);
		*s = 0;
		return (ret);
	}
}
