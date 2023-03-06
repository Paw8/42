/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:07:25 by mokatova          #+#    #+#             */
/*   Updated: 2021/11/22 20:18:51 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	chr;

	i = 0;
	string = (unsigned char *) str;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (string[i] == chr)
			return ((void *)&string[i]);
		i++;
	}
	return (0);
}
