/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:22:20 by mokatova          #+#    #+#             */
/*   Updated: 2021/12/01 00:11:08 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		length;
	char		*string;

	string = (char *) str1;
	i = 0;
	j = 0;
	length = ft_strlen(str2);
	if (length == 0)
		return (string);
	while (string[i] != '\0')
	{
		if (string[i] == str2[j])
		{
			while (string[i + j] == str2[j] && j < length && j + i < len)
				j++;
			if (j == length)
				return (&string[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
