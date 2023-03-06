/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:50:41 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/13 20:33:29 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	checkfile(char *path, int *width)
{
	int		fd;
	char	*line;
	char	*temp;
	int		length;

	*width = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		if (write(1, "No file or empty file!\n", 23))
			exit(0);
	length = getlength(line);
	while (line != NULL)
	{
		temp = loop1(line);
		if (*temp != '\0')
			invalid(line, fd);
		free(line);
		line = get_next_line(fd);
		(*width)++;
	}
	free(line);
	return (length);
}

void	invalid(char *s, int fd)
{
	if (write(1, "Invalid file!\n", 14))
	{
		while (s)
		{
			free(s);
			s = get_next_line(fd);
		}
		free(s);
		close(fd);
		exit(0);
	}
}

char	*loop1(char *s)
{
	while (*s != '\0')
	{
		if (*s == ' ' || *s == '\n')
			s++;
		else if (*s == '-')
		{
			s++;
			if (!ft_isdigit(*s))
				break ;
		}
		else if (ft_isdigit(*s))
			s = loop2(s);
		else
			break ;
	}
	return (s);
}

char	*loop2(char *s)
{
	while ((ft_isdigit(*s) || *s == ' ') && *s)
		s++;
	if (*s == ',')
	{
		s++;
		if (*s == '0')
		{
			s++;
			if (*s == 'x')
			{
				s++;
				return (loop3(s));
			}
			else
				return ("e");
		}
		else
			return ("e");
	}
	return (s);
}

char	*loop3(char *s)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_isdigit(*s) || (*s <= 'F' && *s >= 'A'))
			s++;
		else if (*s <= 'f' && *s >= 'a')
			s++;
		else
			break ;
		i++;
	}
	if (i > 0 && i <= 6 && (*s == ' ' || *s == '\n'))
		return (s);
	else
		return ("e");
}
