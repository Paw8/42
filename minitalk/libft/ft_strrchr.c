/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:26:40 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:13:31 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = 0;
	while (*s)
	{
		if (*s == (char)c)
			find = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (find);
}
